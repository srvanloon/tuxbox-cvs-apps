/*
	Neutrino-GUI  -   DBoxII-Project

	MP3Player by Dirch
	
	Homepage: http://dbox.cyberphoria.org/

	Kommentar:

	Diese GUI wurde von Grund auf neu programmiert und sollte nun vom
	Aufbau und auch den Ausbaumoeglichkeiten gut aussehen. Neutrino basiert
	auf der Client-Server Idee, diese GUI ist also von der direkten DBox-
	Steuerung getrennt. Diese wird dann von Daemons uebernommen.


	License: GPL

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <config.h>

#include <gui/pictureviewer.h>

#include <global.h>
#include <neutrino.h>

#include <daemonc/remotecontrol.h>

#include <driver/fontrenderer.h>
#include <driver/rcinput.h>

#include <gui/nfs.h>

#include <gui/widget/buttons.h>
#include <gui/widget/icons.h>
#include <gui/widget/menue.h>
#include <gui/widget/messagebox.h>
#include <gui/widget/hintbox.h>
#include <gui/widget/stringinput.h>

#include <system/settings.h>

#include <algorithm>
#include <sys/stat.h>
#include <sys/time.h>


//------------------------------------------------------------------------
bool comparePictureByDate (const CPicture& a, const CPicture& b)
{
	return a.Date < b.Date ;
}
//------------------------------------------------------------------------
bool comparePictureByFilename (const CPicture& a, const CPicture& b)
{
	return a.Filename < b.Filename ;
}
//------------------------------------------------------------------------

CPictureViewerGui::CPictureViewerGui()
{
	frameBuffer = CFrameBuffer::getInstance();

	visible = false;
	selected = 0;

	m_sort = FILENAME;
	m_viewer = new CPictureViewer();
	m_filebrowser = new CFileBrowser();
	m_filebrowser->Multi_Select = true;
	m_filebrowser->Dirs_Selectable = true;
	picture_filter.addFilter("png");
	picture_filter.addFilter("bmp");
	picture_filter.addFilter("jpg");
	picture_filter.addFilter("gif");
	m_filebrowser->Filter = &picture_filter;
   if(strlen(g_settings.network_nfs_picturedir)!=0)
      Path = g_settings.network_nfs_picturedir;
	else
      Path = "/";
}

//------------------------------------------------------------------------

CPictureViewerGui::~CPictureViewerGui()
{
	playlist.clear();
	delete m_filebrowser;
	delete m_viewer;
}

//------------------------------------------------------------------------
int CPictureViewerGui::exec(CMenuTarget* parent, const std::string & actionKey)
{
	selected = 0;
	width = 710;
	if((g_settings.screen_EndX- g_settings.screen_StartX) < width)
		width=(g_settings.screen_EndX- g_settings.screen_StartX);
	height = 570;
	if((g_settings.screen_EndY- g_settings.screen_StartY) < height)
		height=(g_settings.screen_EndY- g_settings.screen_StartY);
	buttonHeight = std::min(25,g_Fonts->infobar_small->getHeight());
	theight= g_Fonts->menu_title->getHeight();
	fheight= g_Fonts->menu->getHeight();
	sheight= g_Fonts->infobar_small->getHeight();
	listmaxshow = (height-theight-2*buttonHeight)/(fheight);
	height = theight+2*buttonHeight+listmaxshow*fheight;	// recalc height

	x=(((g_settings.screen_EndX- g_settings.screen_StartX)-width) / 2) + g_settings.screen_StartX;
	y=(((g_settings.screen_EndY- g_settings.screen_StartY)-height)/ 2) + g_settings.screen_StartY;

	m_viewer->SetScaling((CPictureViewer::ScalingMode)g_settings.picviewer_scaling);
	m_viewer->SetVisible(g_settings.screen_StartX, g_settings.screen_EndX, g_settings.screen_StartY, g_settings.screen_EndY);

	if(g_settings.video_Format==1)
		m_viewer->SetAspectRatio(16.0/9);
	else if(g_settings.video_Format==0)
	{
		CControldClient cdc;
		cdc.setVideoFormat(CControldClient::VIDEOFORMAT_4_3);
		m_viewer->SetAspectRatio(4.0/3);
	}
	else
		m_viewer->SetAspectRatio(4.0/3);

	if(parent)
	{
		parent->hide();
	}

	// tell neutrino we're in pic_mode
	CNeutrinoApp::getInstance()->handleMsg( NeutrinoMessages::CHANGEMODE , NeutrinoMessages::mode_pic );
	// remember last mode
	m_LastMode=(CNeutrinoApp::getInstance()->getLastMode() | NeutrinoMessages::norezap);

	g_Sectionsd->setPauseScanning(true); 

	show();

	// free picviewer mem
	m_viewer->Cleanup();

	// Start Sectionsd
	g_Sectionsd->setPauseScanning(false);

	// reset mode to auto if appl.
	if(g_settings.video_Format==0)
	{
		CControldClient cdc;
		cdc.setVideoFormat(CControldClient::VIDEOFORMAT_AUTO);
	}
	
	// Restore last mode
	CNeutrinoApp::getInstance()->handleMsg( NeutrinoMessages::CHANGEMODE , m_LastMode );

	// always exit all	
	return menu_return::RETURN_EXIT_ALL;
}

//------------------------------------------------------------------------

int CPictureViewerGui::show()
{
	int res = -1;

	CLCD::getInstance()->setMode(CLCD::MODE_MENU_UTF8, g_Locale->getText("pictureviewer.head") );
	m_state=MENU;

	uint msg; uint data;
	int timeout;

	bool loop=true;
	bool update=true;
	
	while(loop)
	{
		if(update)
		{
			hide();
			update=false;
			paint();
		}
		
		if(m_state!=SLIDESHOW)
			timeout=50; // egal
		else
		{
			timeout=(m_time+atoi(g_settings.picviewer_slide_time)-(long)time(NULL))*10;
			if(timeout <0 )
				timeout=1;
		}
		g_RCInput->getMsg( &msg, &data, timeout );

		if( msg == CRCInput::RC_home)
		{ //Exit after cancel key
			if(m_state!=MENU)
			{
				endView();
				update=true;
			}
			else
				loop=false;
		}
		else if( msg == CRCInput::RC_timeout )
		{
			// do nothing
			if(m_state==SLIDESHOW)
			{
				m_time=(long)time(NULL);
				unsigned int next=selected+1;
				if( next+1 > playlist.size())
					next=0;
				view(next);
			}
		}
		else if( msg == CRCInput::RC_left)
		{
			if(m_state!=MENU)
			{
				view((selected == 0) ? (playlist.size() - 1) : (selected - 1));
			}
		}
		else if( msg == CRCInput::RC_right)
		{
			if(m_state!=MENU)
			{
				unsigned int next=selected+1;
				if( next+1 > playlist.size())
					next=0;
				view(next);
			}
		}
		else if( msg == CRCInput::RC_up && playlist.size() > 0)
		{
			if(m_state==MENU)
			{
				int prevselected=selected;
				if(selected==0)
				{
					selected = playlist.size()-1;
				}
				else
					selected--;
				paintItem(prevselected - liststart);
				unsigned int oldliststart = liststart;
				liststart = (selected/listmaxshow)*listmaxshow;
				if(oldliststart!=liststart)
				{
					update=true;
				}
				else
				{
					paintItem(selected - liststart);
				}
			}
		}
		else if( msg == CRCInput::RC_down && playlist.size() > 0)
		{
			if(m_state==MENU)
			{
				int prevselected=selected;
				selected = (selected+1)%playlist.size();
				paintItem(prevselected - liststart);
				unsigned int oldliststart = liststart;
				liststart = (selected/listmaxshow)*listmaxshow;
				if(oldliststart!=liststart)
				{
					update=true;
				}
				else
					{
					paintItem(selected - liststart);
				}
			}
		}
		else if( msg == CRCInput::RC_ok && playlist.size() > 0)
		{
			if(m_state==MENU)
			{
				view(selected);
			}
			else
			{
            view(selected);
			}
		}
		else if(msg==CRCInput::RC_red )
		{
			if(m_state==MENU)
			{
				if (playlist.size() > 0)
				{
					CViewList::iterator p = playlist.begin()+selected;
					playlist.erase(p);
					if(selected > playlist.size()-1)
						selected = playlist.size()-1;
					update=true;
				}
			}
		}
		else if(msg==CRCInput::RC_green)
		{
			if(m_state==MENU)
			{
				hide();
				if(m_filebrowser->exec(Path))
				{
					Path=m_filebrowser->getCurrentDir();
					CFileList::iterator files = m_filebrowser->getSelectedFiles()->begin();
					for(; files != m_filebrowser->getSelectedFiles()->end();files++)
					{
						if(files->getType() == CFile::FILE_PICTURE)
						{
							CPicture pic;
							pic.Filename = files->Name;
							std::string tmp   = files->Name.substr(files->Name.rfind('/')+1);
							pic.Name     = tmp.substr(0,tmp.rfind('.'));
							pic.Type     = tmp.substr(tmp.rfind('.')+1);
							struct stat statbuf;
							if(stat(pic.Filename.c_str(),&statbuf) != 0)
								printf("stat error");
							pic.Date     = statbuf.st_mtime;
							playlist.push_back(pic);
						}
						else
							printf("Wrong Filetype %s:%d\n",files->Name.c_str(), files->getType());
						
						if(m_sort==FILENAME)
							std::sort(playlist.begin(),playlist.end(),comparePictureByFilename);
						else if(m_sort==DATE)
							std::sort(playlist.begin(),playlist.end(),comparePictureByDate);
					}
				}
	//				CLCD::getInstance()->setMode(CLCD::MODE_MP3);
				update=true;
			}
		}
		else if(msg==CRCInput::RC_yellow)
		{
			if(m_state==MENU)
			{
				playlist.clear();
				selected=0;
				update=true;
			}
		}
		else if(msg==CRCInput::RC_blue)
		{
			if(m_state==MENU && playlist.size() > 0)
			{
				m_time=(long)time(NULL);
				view(selected);
				m_state=SLIDESHOW;
			}
		}
		else if(msg==CRCInput::RC_help)
		{
			if(m_sort==FILENAME)
			{
				m_sort=DATE;
				std::sort(playlist.begin(),playlist.end(),comparePictureByDate);
			}
			else if(m_sort==DATE)
			{
				m_sort=FILENAME;
				std::sort(playlist.begin(),playlist.end(),comparePictureByFilename);
			}
			update=true;
		}
		else if( msg == CRCInput::RC_1 )
		{ 
			if(m_state==MENU)
			{
			}
			else
			{
				m_viewer->Zoom(2.0/3);
			}

		}
		else if( msg == CRCInput::RC_3 )
		{ 
			if(m_state==MENU)
			{
			}
			else
			{
				m_viewer->Zoom(1.5);
			}

		}
		else if( msg == CRCInput::RC_2 )
		{ 
			if(m_state==MENU)
			{
			}
			else
			{
				m_viewer->Move(0,-50);
			}
		}
		else if( msg == CRCInput::RC_4 )
		{ 
			if(m_state==MENU)
			{
			}
			else
			{
				m_viewer->Move(-50,0);
			}
		}
		else if( msg == CRCInput::RC_6 )
		{ 
			if(m_state==MENU)
			{
			}
			else
			{
				m_viewer->Move(50,0);
			}
		}
		else if( msg == CRCInput::RC_8 )
		{ 
			if(m_state==MENU)
			{
			}
			else
			{
				m_viewer->Move(0,50);
			}
		}
		else if(msg==CRCInput::RC_0)
		{
			view(selected, true);
		}
		else if(msg==CRCInput::RC_setup)
		{
			if(m_state==MENU)
			{
				CNFSSmallMenu nfsMenu;
				nfsMenu.exec(this, "");
				update=true;
				CLCD::getInstance()->setMode(CLCD::MODE_MENU_UTF8, g_Locale->getText("pictureviewer.head") );
			}
		}
		else if(msg == NeutrinoMessages::CHANGEMODE)
		{
			if((data & NeutrinoMessages::mode_mask) !=NeutrinoMessages::mode_pic)
			{
				loop = false;
				m_LastMode=data;
			}
		}
		else if(msg == NeutrinoMessages::RECORD_START ||
				  msg == NeutrinoMessages::ZAPTO ||
				  msg == NeutrinoMessages::STANDBY_ON ||
				  msg == NeutrinoMessages::SHUTDOWN ||
				  msg == NeutrinoMessages::SLEEPTIMER)
		{
			// Exit for Record/Zapto Timers
			if (m_state != MENU)
				endView();
			loop = false;
			g_RCInput->postMsg(msg, data);
		}
		else
		{
			if( CNeutrinoApp::getInstance()->handleMsg( msg, data ) & messages_return::cancel_all )
			{
				loop = false;
			}
		}
	}
	hide();

	return(res);
}

//------------------------------------------------------------------------

void CPictureViewerGui::hide()
{
//	printf("hide(){\n");
	if(visible)
	{
		frameBuffer->paintBackgroundBoxRel(x-1, y-1, width+2, height+2);
		visible = false;
	}
//	printf("hide()}\n");
}

//------------------------------------------------------------------------

void CPictureViewerGui::paintItem(int pos)
{
//	printf("paintItem{\n");
	int ypos = y+ theight + 0 + pos*fheight;
	int color;
	if( (liststart+pos < playlist.size()) && (pos % 2) )
		color = COL_MENUCONTENTDARK;
	else
		color	= COL_MENUCONTENT;

	if(liststart+pos==selected)
		color = COL_MENUCONTENTSELECTED;

	frameBuffer->paintBoxRel(x,ypos, width-15, fheight, color);
	if(liststart+pos<playlist.size())
	{
		std::string tmp = playlist[liststart+pos].Name;
		tmp += " (";
		tmp += playlist[liststart+pos].Type;
		tmp += ')';
		char timestring[18];
		strftime(timestring, 18, "%d-%m-%Y %H:%M", gmtime(&playlist[liststart+pos].Date));
		int w = g_Fonts->menu->getRenderWidth(timestring);
		g_Fonts->menu->RenderString(x+10,ypos+fheight, width-30 - w, tmp, color, fheight);
		g_Fonts->menu->RenderString(x+width-20-w,ypos+fheight, w, timestring, color, fheight);

	}
//	printf("paintItem}\n");
}

//------------------------------------------------------------------------

void CPictureViewerGui::paintHead()
{
//	printf("paintHead{\n");
	std::string strCaption = g_Locale->getText("pictureviewer.head");
	frameBuffer->paintBoxRel(x,y, width,theight, COL_MENUHEAD);
	frameBuffer->paintIcon("mp3.raw",x+7,y+10);
	g_Fonts->menu_title->RenderString(x+35,y+theight+0, width- 45, strCaption, COL_MENUHEAD, 0, true); // UTF-8
	int ypos=y+0;
	if(theight > 26)
		ypos = (theight-26) / 2 + y ;
	frameBuffer->paintIcon(NEUTRINO_ICON_BUTTON_DBOX, x+ width- 30, ypos );
//	printf("paintHead}\n");
}

//------------------------------------------------------------------------
const struct button_label PictureViewerButtons[4] =
{
	{ NEUTRINO_ICON_BUTTON_RED   , "mp3player.delete"        },
	{ NEUTRINO_ICON_BUTTON_GREEN , "mp3player.add"           },
	{ NEUTRINO_ICON_BUTTON_YELLOW, "mp3player.deleteall"     },
	{ NEUTRINO_ICON_BUTTON_BLUE  , "pictureviewer.slideshow" }
};

void CPictureViewerGui::paintFoot()
{
//	printf("paintFoot{\n");
	int ButtonWidth = (width-20) / 4;
	int ButtonWidth2 = (width-50) / 2;
	frameBuffer->paintBoxRel(x,y+(height-2*buttonHeight), width,2*buttonHeight, COL_MENUHEAD);
	frameBuffer->paintHLine(x, x+width,  y+(height-2*buttonHeight), COL_INFOBAR_SHADOW);

	if (!playlist.empty())
	{
		frameBuffer->paintIcon(NEUTRINO_ICON_BUTTON_OKAY, x + 1* ButtonWidth2 + 25, y+(height-buttonHeight)-3);
		g_Fonts->infobar_small->RenderString(x + 1 * ButtonWidth2 + 53 , y+(height-buttonHeight)+24 - 4, 
						     ButtonWidth2- 28, g_Locale->getText("pictureviewer.show"), COL_INFOBAR, 0, true); // UTF-8
		frameBuffer->paintIcon(NEUTRINO_ICON_BUTTON_HELP, x+ 0* ButtonWidth2 + 25, y+(height-buttonHeight)-3);
		std::string tmp = g_Locale->getText("pictureviewer.sortorder");
		tmp += ' ';
		if(m_sort==FILENAME)
			tmp += g_Locale->getText("pictureviewer.sortorder.date");
		else if(m_sort==DATE)
			tmp += g_Locale->getText("pictureviewer.sortorder.filename");
		g_Fonts->infobar_small->RenderString(x+ 0* ButtonWidth2 +53 , y+(height-buttonHeight)+24 - 4, 
														 ButtonWidth2- 28, tmp, COL_INFOBAR, 0, true); // UTF-8


		::paintButtons(frameBuffer, g_Fonts->infobar_small, g_Locale, x + 10, y + (height - 2 * buttonHeight) + 4, ButtonWidth, 4, PictureViewerButtons);
	}
	else
		::paintButtons(frameBuffer, g_Fonts->infobar_small, g_Locale, x + ButtonWidth + 10, y + (height - 2 * buttonHeight) + 4, ButtonWidth, 1, &(PictureViewerButtons[1]));
//	printf("paintFoot}\n");
}
//------------------------------------------------------------------------
void CPictureViewerGui::paintInfo()
{
}
//------------------------------------------------------------------------

void CPictureViewerGui::paint()
{
	liststart = (selected/listmaxshow)*listmaxshow;

	paintHead();
	for(unsigned int count=0;count<listmaxshow;count++)
	{
		paintItem(count);
	}

	int ypos = y+ theight;
	int sb = fheight* listmaxshow;
	frameBuffer->paintBoxRel(x+ width- 15,ypos, 15, sb,  COL_MENUCONTENT+ 1);

	int sbc= ((playlist.size()- 1)/ listmaxshow)+ 1;
	float sbh= (sb- 4)/ sbc;
	int sbs= (selected/listmaxshow);

	frameBuffer->paintBoxRel(x+ width- 13, ypos+ 2+ int(sbs* sbh) , 11, int(sbh),  COL_MENUCONTENT+ 3);

	paintFoot();
	paintInfo();
	
	visible = true;
}

void CPictureViewerGui::view(unsigned int index, bool unscaled)
{
	selected=index;
	
	CLCD::getInstance()->showMenuText(0, playlist[index].Name );
	char timestring[19];
	strftime(timestring, 18, "%d-%m-%Y %H:%M", gmtime(&playlist[index].Date));
	CLCD::getInstance()->showMenuText(1, timestring );
	
	if(m_state == MENU)
		frameBuffer->setMode(720,576,16);
	if(unscaled)
		m_viewer->DecodeImage(playlist[index].Filename, true, unscaled);
	m_viewer->ShowImage(playlist[index].Filename, unscaled);

	//Decode next
	unsigned int next=selected+1;
	if(next > playlist.size()-1)
		next=0;
	if(m_state==MENU)
		m_state=VIEW;
	if(m_state==VIEW)
		m_viewer->DecodeImage(playlist[next].Filename,true);
	else
		m_viewer->DecodeImage(playlist[next].Filename,false);
}

void CPictureViewerGui::endView()
{
	if(m_state != MENU)
	{
		frameBuffer->setMode(720,576,8);
		frameBuffer->ClearFrameBuffer();
		m_state=MENU;
	}
}
