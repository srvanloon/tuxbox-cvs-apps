#ifndef __locals_intern__
#define __locals_intern__

/*
 * $Id: locals_intern.h,v 1.113 2008/02/16 20:36:05 seife Exp $
 *
 * (C) 2004 by thegoodguy <thegoodguy@berlios.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

const char * locale_real_names[] =
{
	"INTERNAL ERROR - PLEASE REPORT",
	"AUDIOSelectMenue.head",
	"EPGMenu.epgplus",
	"EPGMenu.eventinfo",
	"EPGMenu.eventlist",
	"EPGMenu.head",
	"EPGMenu.streaminfo",
	"EPGPlus.actions",
	"EPGPlus.bybouquet_mode",
	"EPGPlus.bypage_mode",
	"EPGPlus.change_font_size",
	"EPGPlus.change_font_style",
	"EPGPlus.change_size",
	"EPGPlus.channelentry_font",
	"EPGPlus.channelentry_separationlineheight",
	"EPGPlus.channelentry_width",
	"EPGPlus.channelevententry_font",
	"EPGPlus.edit_fonts",
	"EPGPlus.edit_sizes",
	"EPGPlus.font_style_bold",
	"EPGPlus.font_style_italic",
	"EPGPlus.font_style_regular",
	"EPGPlus.footer_fontbouquetchannelname",
	"EPGPlus.footer_fontbuttons",
	"EPGPlus.footer_fonteventdescription",
	"EPGPlus.footer_fonteventshortdescription",
	"EPGPlus.head",
	"EPGPlus.header_font",
	"EPGPlus.horgap1_height",
	"EPGPlus.horgap2_height",
	"EPGPlus.next_bouquet",
	"EPGPlus.options",
	"EPGPlus.page_down",
	"EPGPlus.page_up",
	"EPGPlus.prev_bouquet",
	"EPGPlus.record",
	"EPGPlus.refresh_epg",
	"EPGPlus.remind",
	"EPGPlus.reset_settings",
	"EPGPlus.save_settings",
	"EPGPlus.scroll_mode",
	"EPGPlus.select_font_name",
	"EPGPlus.settings",
	"EPGPlus.slider_width",
	"EPGPlus.stretch_mode",
	"EPGPlus.swap_mode",
	"EPGPlus.timeline_fontdate",
	"EPGPlus.timeline_fonttime",
	"EPGPlus.vergap1_width",
	"EPGPlus.vergap2_width",
	"EPGPlus.view_mode",
	"GENRE.ARTS.0",
	"GENRE.ARTS.1",
	"GENRE.ARTS.10",
	"GENRE.ARTS.11",
	"GENRE.ARTS.2",
	"GENRE.ARTS.3",
	"GENRE.ARTS.4",
	"GENRE.ARTS.5",
	"GENRE.ARTS.6",
	"GENRE.ARTS.7",
	"GENRE.ARTS.8",
	"GENRE.ARTS.9",
	"GENRE.CHILDRENs_PROGRAMMES.0",
	"GENRE.CHILDRENs_PROGRAMMES.1",
	"GENRE.CHILDRENs_PROGRAMMES.2",
	"GENRE.CHILDRENs_PROGRAMMES.3",
	"GENRE.CHILDRENs_PROGRAMMES.4",
	"GENRE.CHILDRENs_PROGRAMMES.5",
	"GENRE.DOCUS_MAGAZINES.0",
	"GENRE.DOCUS_MAGAZINES.1",
	"GENRE.DOCUS_MAGAZINES.2",
	"GENRE.DOCUS_MAGAZINES.3",
	"GENRE.DOCUS_MAGAZINES.4",
	"GENRE.DOCUS_MAGAZINES.5",
	"GENRE.DOCUS_MAGAZINES.6",
	"GENRE.DOCUS_MAGAZINES.7",
	"GENRE.MOVIE.0",
	"GENRE.MOVIE.1",
	"GENRE.MOVIE.2",
	"GENRE.MOVIE.3",
	"GENRE.MOVIE.4",
	"GENRE.MOVIE.5",
	"GENRE.MOVIE.6",
	"GENRE.MOVIE.7",
	"GENRE.MOVIE.8",
	"GENRE.MUSIC_DANCE.0",
	"GENRE.MUSIC_DANCE.1",
	"GENRE.MUSIC_DANCE.2",
	"GENRE.MUSIC_DANCE.3",
	"GENRE.MUSIC_DANCE.4",
	"GENRE.MUSIC_DANCE.5",
	"GENRE.MUSIC_DANCE.6",
	"GENRE.NEWS.0",
	"GENRE.NEWS.1",
	"GENRE.NEWS.2",
	"GENRE.NEWS.3",
	"GENRE.NEWS.4",
	"GENRE.SHOW.0",
	"GENRE.SHOW.1",
	"GENRE.SHOW.2",
	"GENRE.SHOW.3",
	"GENRE.SOCIAL_POLITICAL.0",
	"GENRE.SOCIAL_POLITICAL.1",
	"GENRE.SOCIAL_POLITICAL.2",
	"GENRE.SOCIAL_POLITICAL.3",
	"GENRE.SPORTS.0",
	"GENRE.SPORTS.1",
	"GENRE.SPORTS.10",
	"GENRE.SPORTS.11",
	"GENRE.SPORTS.2",
	"GENRE.SPORTS.3",
	"GENRE.SPORTS.4",
	"GENRE.SPORTS.5",
	"GENRE.SPORTS.6",
	"GENRE.SPORTS.7",
	"GENRE.SPORTS.8",
	"GENRE.SPORTS.9",
	"GENRE.TRAVEL_HOBBIES.0",
	"GENRE.TRAVEL_HOBBIES.1",
	"GENRE.TRAVEL_HOBBIES.2",
	"GENRE.TRAVEL_HOBBIES.3",
	"GENRE.TRAVEL_HOBBIES.4",
	"GENRE.TRAVEL_HOBBIES.5",
	"GENRE.TRAVEL_HOBBIES.6",
	"GENRE.TRAVEL_HOBBIES.7",
	"GENRE.UNKNOWN",
	"apids.hint_1",
	"apids.hint_2",
	"apidselector.head",
	"audiomenu.PCMOffset",
	"audiomenu.analogout",
	"audiomenu.audio_left_right_selectable",
	"audiomenu.audiochannel_up_down_enable",
	"audiomenu.avs",
	"audiomenu.avs_control",
	"audiomenu.dolbydigital",
	"audiomenu.head",
	"audiomenu.lirc",
	"audiomenu.monoleft",
	"audiomenu.monoright",
	"audiomenu.ost",
	"audiomenu.stereo",
	"audiomenu.volumebar_audiosteps",
	"audioplayer.add",
	"audioplayer.artist_title",
	"audioplayer.building_search_index",
	"audioplayer.button_select_title_by_id",
	"audioplayer.button_select_title_by_name",
	"audioplayer.defdir",
	"audioplayer.delete",
	"audioplayer.deleteall",
	"audioplayer.display_order",
	"audioplayer.enable_sc_metadata",
	"audioplayer.fastforward",
	"audioplayer.follow",
	"audioplayer.head",
	"audioplayer.highprio",
	"audioplayer.id3scan",
	"audioplayer.jump_backwards",
	"audioplayer.jump_dialog_hint1",
	"audioplayer.jump_dialog_hint2",
	"audioplayer.jump_dialog_title",
	"audioplayer.jump_forwards",
	"audioplayer.keylevel",
	"audioplayer.load_radio_stations",
	"audioplayer.name",
	"audioplayer.pause",
	"audioplayer.play",
	"audioplayer.playing",
	"audioplayer.playlist_fileerror_msg",
	"audioplayer.playlist_fileerror_title",
	"audioplayer.playlist_fileoverwrite_msg",
	"audioplayer.playlist_fileoverwrite_title",
	"audioplayer.playlist_name",
	"audioplayer.playlist_name_hint1",
	"audioplayer.playlist_name_hint2",
	"audioplayer.reading_files",
	"audioplayer.repeat_on",
	"audioplayer.rewind",
	"audioplayer.save_playlist",
	"audioplayer.screensaver_timeout",
	"audioplayer.select_title_by_name",
	"audioplayer.show_playlist",
	"audioplayer.shuffle",
	"audioplayer.stop",
	"audioplayer.title_artist",
	"audioplayerpicsettings.general",
	"bookmarkmanager.delete",
	"bookmarkmanager.name",
	"bookmarkmanager.rename",
	"bookmarkmanager.select",
	"bouqueteditor.add",
	"bouqueteditor.bouquetname",
	"bouqueteditor.delete",
	"bouqueteditor.discardingchanges",
	"bouqueteditor.hide",
	"bouqueteditor.lock",
	"bouqueteditor.move",
	"bouqueteditor.name",
	"bouqueteditor.newbouquetname",
	"bouqueteditor.rename",
	"bouqueteditor.return",
	"bouqueteditor.savechanges?",
	"bouqueteditor.savingchanges",
	"bouqueteditor.switch",
	"bouqueteditor.switchmode",
	"bouquetlist.head",
	"cablesetup.provider",
	"channellist.head",
	"channellist.nonefound",
	"channellist.since",
	"channellist.start",
	"colorchooser.alpha",
	"colorchooser.blue",
	"colorchooser.green",
	"colorchooser.red",
	"colormenu.background",
	"colormenu.background_head",
	"colormenu.fade",
	"colormenu.font",
	"colormenu.gtx_alpha",
	"colormenu.head",
	"colormenu.menucolors",
	"colormenu.statusbar",
	"colormenu.textcolor",
	"colormenu.textcolor_head",
	"colormenu.themeselect",
	"colormenu.timing",
	"colormenusetup.head",
	"colormenusetup.menucontent",
	"colormenusetup.menucontent_inactive",
	"colormenusetup.menucontent_selected",
	"colormenusetup.menuhead",
	"colorstatusbar.head",
	"colorstatusbar.text",
	"colorthememenu.head",
	"colorthememenu.head2",
	"colorthememenu.name",
	"colorthememenu.neutrino_theme",
	"colorthememenu.question",
	"colorthememenu.save",
	"colorthememenu.select1",
	"colorthememenu.select2",
	"date.Apr",
	"date.Aug",
	"date.Dec",
	"date.Feb",
	"date.Fri",
	"date.Jan",
	"date.Jul",
	"date.Jun",
	"date.Mar",
	"date.May",
	"date.Mon",
	"date.Nov",
	"date.Oct",
	"date.Sat",
	"date.Sep",
	"date.Sun",
	"date.Thu",
	"date.Tue",
	"date.Wed",
	"driversettings.bootinfo",
	"driversettings.driver_boot",
	"driversettings.fb_destination",
	"driversettings.head",
	"driversettings.hwsections",
	"driversettings.noaviawatchdog",
	"driversettings.noenxwatchdog",
	"driversettings.pmtupdate",
	"driversettings.sptsmode",
	"driversettings.startbhdriver",
	"epgextended.actors",
	"epgextended.director",
	"epgextended.guests",
	"epgextended.original_title",
	"epgextended.presenter",
	"epgextended.year_of_production",
	"epglist.head",
	"epglist.noevents",
	"epgviewer.More_Screenings",
	"epgviewer.nodetailed",
	"epgviewer.notfound",
	"eventfinder.head",
	"eventfinder.keyword",
	"eventfinder.search",
	"eventfinder.search_within_epg",
	"eventfinder.search_within_list",
	"eventfinder.searching",
	"eventfinder.start_search",
	"eventlistbar.channelswitch",
	"eventlistbar.eventsort",
	"eventlistbar.recordevent",
	"experimentalsettings",
	"experimentalsettings.head",
	"favorites.addchannel",
	"favorites.bouquetname",
	"favorites.bqcreated",
	"favorites.chadded",
	"favorites.chalreadyinbq",
	"favorites.finalhint",
	"favorites.menueadd",
	"favorites.nobouquets",
	"filebrowser.delete",
	"filebrowser.denydirectoryleave",
	"filebrowser.dodelete1",
	"filebrowser.dodelete2",
	"filebrowser.filter.active",
	"filebrowser.filter.inactive",
	"filebrowser.head",
	"filebrowser.mark",
	"filebrowser.nextpage",
	"filebrowser.prevpage",
	"filebrowser.scan",
	"filebrowser.select",
	"filebrowser.showrights",
	"filebrowser.sort.date",
	"filebrowser.sort.name",
	"filebrowser.sort.namedirsfirst",
	"filebrowser.sort.size",
	"filebrowser.sort.type",
	"filesystem.is.utf8",
	"filesystem.is.utf8.option.iso8859.1",
	"filesystem.is.utf8.option.utf8",
	"flashupdate.actionreadflash",
	"flashupdate.cantopenfile",
	"flashupdate.cantopenmtd",
	"flashupdate.checkupdate",
	"flashupdate.currentreleasecycle",
	"flashupdate.currentversion_sep",
	"flashupdate.currentversiondate",
	"flashupdate.currentversionsnapshot",
	"flashupdate.currentversiontime",
	"flashupdate.erasefailed",
	"flashupdate.erasing",
	"flashupdate.experimentalimage",
	"flashupdate.expertfunctions",
	"flashupdate.fileis0bytes",
	"flashupdate.fileselector",
	"flashupdate.flashreadyreboot",
	"flashupdate.getinfofile",
	"flashupdate.getinfofileerror",
	"flashupdate.getupdatefile",
	"flashupdate.getupdatefileerror",
	"flashupdate.globalprogress",
	"flashupdate.head",
	"flashupdate.md5check",
	"flashupdate.md5sumerror",
	"flashupdate.msgbox",
	"flashupdate.msgbox_manual",
	"flashupdate.mtdselector",
	"flashupdate.programmingflash",
	"flashupdate.proxypassword",
	"flashupdate.proxypassword_hint1",
	"flashupdate.proxypassword_hint2",
	"flashupdate.proxyserver",
	"flashupdate.proxyserver_hint1",
	"flashupdate.proxyserver_hint2",
	"flashupdate.proxyserver_sep",
	"flashupdate.proxyusername",
	"flashupdate.proxyusername_hint1",
	"flashupdate.proxyusername_hint2",
	"flashupdate.readflash",
	"flashupdate.readflashmtd",
	"flashupdate.ready",
	"flashupdate.reallyflashchipset",
	"flashupdate.reallyflashmtd",
	"flashupdate.savesuccess",
	"flashupdate.selectimage",
	"flashupdate.squashfs.noversion",
	"flashupdate.titlereadflash",
	"flashupdate.titlewriteflash",
	"flashupdate.updatemode",
	"flashupdate.updatemode_internet",
	"flashupdate.updatemode_manual",
	"flashupdate.url_file",
	"flashupdate.versioncheck",
	"flashupdate.writeflash",
	"flashupdate.writeflashmtd",
	"flashupdate.wrongbase",
	"fontmenu.channellist",
	"fontmenu.epg",
	"fontmenu.eventlist",
	"fontmenu.gamelist",
	"fontmenu.head",
	"fontmenu.infobar",
	"fontsize.channel_num_zap",
	"fontsize.channellist",
	"fontsize.channellist_descr",
	"fontsize.channellist_number",
	"fontsize.epg_date",
	"fontsize.epg_info1",
	"fontsize.epg_info2",
	"fontsize.epg_title",
	"fontsize.eventlist_datetime",
	"fontsize.eventlist_itemlarge",
	"fontsize.eventlist_itemsmall",
	"fontsize.eventlist_title",
	"fontsize.filebrowser_item",
	"fontsize.gamelist_itemlarge",
	"fontsize.gamelist_itemsmall",
	"fontsize.hint",
	"fontsize.imageinfo_info",
	"fontsize.imageinfo_small",
	"fontsize.infobar_channame",
	"fontsize.infobar_info",
	"fontsize.infobar_number",
	"fontsize.infobar_small",
	"fontsize.menu",
	"fontsize.menu_info",
	"fontsize.menu_title",
	"generic.empty",
	"gtxalpha.alpha1",
	"gtxalpha.alpha2",
	"imageinfo.chipset",
	"imageinfo.creator",
	"imageinfo.cvslevel",
	"imageinfo.date",
	"imageinfo.details",
	"imageinfo.dokumentation",
	"imageinfo.forum",
	"imageinfo.head",
	"imageinfo.homepage",
	"imageinfo.image",
	"imageinfo.imagetype",
	"imageinfo.info",
	"imageinfo.license",
	"imageinfo.noteflashtype",
	"imageinfo.partitions",
	"imageinfo.support",
	"imageinfo.supporthere",
	"imageinfo.version",
	"inetradio.name",
	"infoviewer.epginfo_expensive_message",
	"infoviewer.epginfo_simple_message",
	"infoviewer.epgnotload",
	"infoviewer.epgwait",
	"infoviewer.eventlist",
	"infoviewer.languages",
	"infoviewer.message_now",
	"infoviewer.message_to",
	"infoviewer.motor_moving",
	"infoviewer.next",
	"infoviewer.nocurrent",
	"infoviewer.noepg",
	"infoviewer.notavailable",
	"infoviewer.now",
	"infoviewer.selecttime",
	"infoviewer.streaminfo",
	"infoviewer.subchan_disp_pos",
	"infoviewer.subservice",
	"infoviewer.waittime",
	"ipsetup.hint_1",
	"ipsetup.hint_2",
	"keybindingmenu.RC",
	"keybindingmenu.addrecord",
	"keybindingmenu.addrecord_head",
	"keybindingmenu.addremind",
	"keybindingmenu.addremind_head",
	"keybindingmenu.allchannels_on_ok",
	"keybindingmenu.bouquetchannels_on_ok",
	"keybindingmenu.bouquetdown",
	"keybindingmenu.bouquetdown_head",
	"keybindingmenu.bouquethandling",
	"keybindingmenu.bouquetlist_on_ok",
	"keybindingmenu.bouquetup",
	"keybindingmenu.bouquetup_head",
	"keybindingmenu.cancel",
	"keybindingmenu.cancel_head",
	"keybindingmenu.channeldown",
	"keybindingmenu.channeldown_head",
	"keybindingmenu.channellist",
	"keybindingmenu.channelup",
	"keybindingmenu.channelup_head",
	"keybindingmenu.head",
	"keybindingmenu.lastchannel",
	"keybindingmenu.lastchannel_head",
	"keybindingmenu.modechange",
	"keybindingmenu.pagedown",
	"keybindingmenu.pagedown_head",
	"keybindingmenu.pageup",
	"keybindingmenu.pageup_head",
	"keybindingmenu.quickzap",
	"keybindingmenu.reload",
	"keybindingmenu.reload_head",
	"keybindingmenu.repeatblock",
	"keybindingmenu.repeatblockgeneric",
	"keybindingmenu.sort",
	"keybindingmenu.sort_head",
	"keybindingmenu.subchanneldown",
	"keybindingmenu.subchanneldown_head",
	"keybindingmenu.subchannelup",
	"keybindingmenu.subchannelup_head",
	"keybindingmenu.tvradiomode",
	"keybindingmenu.tvradiomode_head",
	"keybindingmenu.zaphistory",
	"keybindingmenu.zaphistory_head",
	"keychooser.head",
	"keychooser.text1",
	"keychooser.text2",
	"keychoosermenu.currentkey",
	"keychoosermenu.setnew",
	"keychoosermenu.setnone",
	"languagesetup.head",
	"languagesetup.select",
	"lcdcontroler.brightness",
	"lcdcontroler.brightnessstandby",
	"lcdcontroler.contrast",
	"lcdcontroler.head",
	"lcdmenu.autodimm",
	"lcdmenu.dim_brightness",
	"lcdmenu.dim_time",
	"lcdmenu.head",
	"lcdmenu.inverse",
	"lcdmenu.lcdcontroler",
	"lcdmenu.power",
	"lcdmenu.statusline",
	"lcdmenu.statusline.both",
	"lcdmenu.statusline.both_audio",
	"lcdmenu.statusline.playtime",
	"lcdmenu.statusline.volume",
	"mainmenu.audioplayer",
	"mainmenu.clearsectionsd",
	"mainmenu.games",
	"mainmenu.head",
	"mainmenu.movieplayer",
	"mainmenu.pausesectionsd",
	"mainmenu.pictureviewer",
	"mainmenu.radiomode",
	"mainmenu.reboot",
	"mainmenu.recording",
	"mainmenu.recording_start",
	"mainmenu.recording_stop",
	"mainmenu.scartmode",
	"mainmenu.scripts",
	"mainmenu.service",
	"mainmenu.settings",
	"mainmenu.shutdown",
	"mainmenu.sleeptimer",
	"mainmenu.tvmode",
	"mainmenu.upnpbrowser",
	"mainsettings.audio",
	"mainsettings.colors",
	"mainsettings.driver",
	"mainsettings.head",
	"mainsettings.keybinding",
	"mainsettings.language",
	"mainsettings.lcd",
	"mainsettings.misc",
	"mainsettings.network",
	"mainsettings.recording",
	"mainsettings.savesettingsnow",
	"mainsettings.savesettingsnow_hint",
	"mainsettings.streaming",
	"mainsettings.video",
	"menu.back",
	"messagebox.back",
	"messagebox.cancel",
	"messagebox.discard",
	"messagebox.error",
	"messagebox.info",
	"messagebox.no",
	"messagebox.yes",
	"miscsettings.epg_cache",
	"miscsettings.epg_cache_hint1",
	"miscsettings.epg_cache_hint2",
	"miscsettings.epg_dir",
	"miscsettings.epg_extendedcache",
	"miscsettings.epg_extendedcache_hint1",
	"miscsettings.epg_extendedcache_hint2",
	"miscsettings.epg_head",
	"miscsettings.epg_max_events",
	"miscsettings.epg_max_events_hint1",
	"miscsettings.epg_max_events_hint2",
	"miscsettings.epg_old_events",
	"miscsettings.epg_old_events_hint1",
	"miscsettings.epg_old_events_hint2",
	"miscsettings.general",
	"miscsettings.head",
	"miscsettings.infobar",
	"miscsettings.infobar_sat_display",
	"miscsettings.infobar_show",
	"miscsettings.osd_specials",
	"miscsettings.show_mute_icon",
	"miscsettings.show_mute_icon_no",
	"miscsettings.show_mute_icon_not_in_ac3mode",
	"miscsettings.show_mute_icon_yes",
	"miscsettings.shutdown_count",
	"miscsettings.shutdown_count_hint1",
	"miscsettings.shutdown_count_hint2",
	"miscsettings.shutdown_real",
	"miscsettings.shutdown_real_rcdelay",
	"miscsettings.tuxtxt_cache",
	"miscsettings.virtual_zap_mode",
	"miscsettings.volumebar_disp_pos",
	"motorcontrol.head",
	"moviebrowser.book_clear_all",
	"moviebrowser.book_head",
	"moviebrowser.book_lastmoviestop",
	"moviebrowser.book_movieend",
	"moviebrowser.book_moviestart",
	"moviebrowser.book_name",
	"moviebrowser.book_new",
	"moviebrowser.book_position",
	"moviebrowser.book_type",
	"moviebrowser.book_type_backward",
	"moviebrowser.book_type_forward",
	"moviebrowser.browser_frame_high",
	"moviebrowser.browser_row_head",
	"moviebrowser.browser_row_item",
	"moviebrowser.browser_row_nr",
	"moviebrowser.browser_row_width",
	"moviebrowser.dir",
	"moviebrowser.dir_head",
	"moviebrowser.edit_book",
	"moviebrowser.edit_book_name_info1",
	"moviebrowser.edit_book_name_info2",
	"moviebrowser.edit_book_pos_info1",
	"moviebrowser.edit_book_pos_info2",
	"moviebrowser.edit_book_type_info1",
	"moviebrowser.edit_book_type_info2",
	"moviebrowser.edit_serie",
	"moviebrowser.error_no_movies",
	"moviebrowser.foot_filter",
	"moviebrowser.foot_play",
	"moviebrowser.foot_sort",
	"moviebrowser.head",
	"moviebrowser.head_filter",
	"moviebrowser.head_playlist",
	"moviebrowser.head_recordlist",
	"moviebrowser.hide_series",
	"moviebrowser.hint_jumpbackward",
	"moviebrowser.hint_jumpforward",
	"moviebrowser.hint_movieend",
	"moviebrowser.hint_newbook_backward",
	"moviebrowser.hint_newbook_forward",
	"moviebrowser.info_audio",
	"moviebrowser.info_channel",
	"moviebrowser.info_filename",
	"moviebrowser.info_genre_major",
	"moviebrowser.info_genre_minor",
	"moviebrowser.info_head",
	"moviebrowser.info_head_update",
	"moviebrowser.info_info1",
	"moviebrowser.info_info2",
	"moviebrowser.info_length",
	"moviebrowser.info_parental_lockage",
	"moviebrowser.info_parental_lockage_0year",
	"moviebrowser.info_parental_lockage_12year",
	"moviebrowser.info_parental_lockage_16year",
	"moviebrowser.info_parental_lockage_18year",
	"moviebrowser.info_parental_lockage_6year",
	"moviebrowser.info_parental_lockage_8year",
	"moviebrowser.info_parental_lockage_always",
	"moviebrowser.info_path",
	"moviebrowser.info_prevplaydate",
	"moviebrowser.info_prodcountry",
	"moviebrowser.info_prodyear",
	"moviebrowser.info_quality",
	"moviebrowser.info_recorddate",
	"moviebrowser.info_serie",
	"moviebrowser.info_size",
	"moviebrowser.info_title",
	"moviebrowser.info_videoformat",
	"moviebrowser.last_play_max_items",
	"moviebrowser.last_record_max_items",
	"moviebrowser.load_default",
	"moviebrowser.menu_directories_head",
	"moviebrowser.menu_help_head",
	"moviebrowser.menu_main_bookmarks",
	"moviebrowser.menu_main_head",
	"moviebrowser.menu_main_movieinfo",
	"moviebrowser.menu_main_saveandback",
	"moviebrowser.menu_nfs_head",
	"moviebrowser.menu_parental_lock_activated",
	"moviebrowser.menu_parental_lock_activated_no",
	"moviebrowser.menu_parental_lock_activated_no_temp",
	"moviebrowser.menu_parental_lock_activated_yes",
	"moviebrowser.menu_parental_lock_head",
	"moviebrowser.menu_parental_lock_rate_head",
	"moviebrowser.menu_save",
	"moviebrowser.menu_save_all",
	"moviebrowser.option_browser",
	"moviebrowser.reload_at_start",
	"moviebrowser.remount_at_start",
	"moviebrowser.scan_for_movies",
	"moviebrowser.serie_auto_create",
	"moviebrowser.serie_existingname",
	"moviebrowser.serie_head",
	"moviebrowser.serie_name",
	"moviebrowser.short_audio",
	"moviebrowser.short_book",
	"moviebrowser.short_channel",
	"moviebrowser.short_country",
	"moviebrowser.short_filename",
	"moviebrowser.short_format",
	"moviebrowser.short_genre_major",
	"moviebrowser.short_genre_minor",
	"moviebrowser.short_info1",
	"moviebrowser.short_info2",
	"moviebrowser.short_length",
	"moviebrowser.short_parental_lockage",
	"moviebrowser.short_path",
	"moviebrowser.short_prevplaydate",
	"moviebrowser.short_prodyear",
	"moviebrowser.short_quality",
	"moviebrowser.short_recorddate",
	"moviebrowser.short_serie",
	"moviebrowser.short_size",
	"moviebrowser.short_title",
	"moviebrowser.start_head",
	"moviebrowser.start_record_start",
	"moviebrowser.update_if_dest_empty_only",
	"moviebrowser.use_dir",
	"moviebrowser.use_movie_dir",
	"moviebrowser.use_rec_dir",
	"movieplayer.bookmark",
	"movieplayer.bookmarkname",
	"movieplayer.bookmarkname_hint1",
	"movieplayer.bookmarkname_hint2",
	"movieplayer.buffering",
	"movieplayer.defdir",
	"movieplayer.defplugin",
	"movieplayer.dvdplayback",
	"movieplayer.fileplayback",
	"movieplayer.goto",
	"movieplayer.goto.h1",
	"movieplayer.goto.h2",
	"movieplayer.head",
	"movieplayer.nostreamingserver",
	"movieplayer.pleasewait",
	"movieplayer.toomanybookmarks",
	"movieplayer.tshelp1",
	"movieplayer.tshelp10",
	"movieplayer.tshelp11",
	"movieplayer.tshelp12",
	"movieplayer.tshelp13",
	"movieplayer.tshelp14",
	"movieplayer.tshelp15",
	"movieplayer.tshelp16",
	"movieplayer.tshelp17",
	"movieplayer.tshelp18",
	"movieplayer.tshelp19",
	"movieplayer.tshelp2",
	"movieplayer.tshelp20",
	"movieplayer.tshelp21",
	"movieplayer.tshelp22",
	"movieplayer.tshelp3",
	"movieplayer.tshelp4",
	"movieplayer.tshelp5",
	"movieplayer.tshelp6",
	"movieplayer.tshelp7",
	"movieplayer.tshelp8",
	"movieplayer.tshelp9",
	"movieplayer.tsplayback",
	"movieplayer.tsplayback_pc",
	"movieplayer.vcdplayback",
	"movieplayer.vlchelp1",
	"movieplayer.vlchelp10",
	"movieplayer.vlchelp11",
	"movieplayer.vlchelp12",
	"movieplayer.vlchelp13",
	"movieplayer.vlchelp14",
	"movieplayer.vlchelp15",
	"movieplayer.vlchelp16",
	"movieplayer.vlchelp2",
	"movieplayer.vlchelp3",
	"movieplayer.vlchelp4",
	"movieplayer.vlchelp5",
	"movieplayer.vlchelp6",
	"movieplayer.vlchelp7",
	"movieplayer.vlchelp8",
	"movieplayer.vlchelp9",
	"movieplayer.wrongvlcversion",
	"networkmenu.broadcast",
	"networkmenu.dhcp",
	"networkmenu.gateway",
	"networkmenu.head",
	"networkmenu.ipaddress",
	"networkmenu.mount",
	"networkmenu.nameserver",
	"networkmenu.netmask",
	"networkmenu.ntpenable",
	"networkmenu.ntprefresh",
	"networkmenu.ntprefresh_hint1",
	"networkmenu.ntprefresh_hint2",
	"networkmenu.ntpserver",
	"networkmenu.ntpserver_hint1",
	"networkmenu.ntpserver_hint2",
	"networkmenu.ntptitle",
	"networkmenu.setupnow",
	"networkmenu.setuponstartup",
	"networkmenu.show",
	"networkmenu.test",
	"nfs.alreadymounted",
	"nfs.automount",
	"nfs.dir",
	"nfs.ip",
	"nfs.localdir",
	"nfs.mount",
	"nfs.mount_options",
	"nfs.mounterror",
	"nfs.mounterror_notsup",
	"nfs.mountnow",
	"nfs.mountok",
	"nfs.mounttimeout",
	"nfs.password",
	"nfs.remount",
	"nfs.type",
	"nfs.type_cifs",
	"nfs.type_lufs",
	"nfs.type_nfs",
	"nfs.umount",
	"nfs.umounterror",
	"nfs.username",
	"nfsmenu.head",
	"nvod.percentage",
	"nvod.starting",
	"nvodselector.directormode",
	"nvodselector.head",
	"nvodselector.subservice",
	"options.default",
	"options.fb",
	"options.ntp_off",
	"options.ntp_on",
	"options.null",
	"options.off",
	"options.on",
	"options.on.without_messages",
	"options.serial",
	"parentallock.changepin",
	"parentallock.changepin_hint1",
	"parentallock.changetolocked",
	"parentallock.head",
	"parentallock.lockage",
	"parentallock.lockage12",
	"parentallock.lockage16",
	"parentallock.lockage18",
	"parentallock.lockedchannel",
	"parentallock.lockedprogram",
	"parentallock.never",
	"parentallock.onsignal",
	"parentallock.parentallock",
	"parentallock.prompt",
	"personalize.access",
	"personalize.disabled",
	"personalize.enabled",
	"personalize.head",
	"personalize.help",
	"personalize.help_line1",
	"personalize.help_line2",
	"personalize.help_line3",
	"personalize.help_line4",
	"personalize.help_line5",
	"personalize.help_line6",
	"personalize.help_line7",
	"personalize.help_line8",
	"personalize.menuconfiguration",
	"personalize.menudisabledhint",
	"personalize.notprotected",
	"personalize.notvisible",
	"personalize.pin",
	"personalize.pincode",
	"personalize.pinhint",
	"personalize.pinprotect",
	"personalize.pinstatus",
	"personalize.saverestart",
	"personalize.setupmenuwithpin",
	"personalize.stprotect",
	"personalize.svprotect",
	"personalize.visible",
	"pictureviewer.decode_server_ip",
	"pictureviewer.decode_server_port",
	"pictureviewer.defdir",
	"pictureviewer.head",
	"pictureviewer.help1",
	"pictureviewer.help10",
	"pictureviewer.help11",
	"pictureviewer.help12",
	"pictureviewer.help13",
	"pictureviewer.help14",
	"pictureviewer.help15",
	"pictureviewer.help16",
	"pictureviewer.help17",
	"pictureviewer.help18",
	"pictureviewer.help19",
	"pictureviewer.help2",
	"pictureviewer.help20",
	"pictureviewer.help21",
	"pictureviewer.help22",
	"pictureviewer.help3",
	"pictureviewer.help4",
	"pictureviewer.help5",
	"pictureviewer.help6",
	"pictureviewer.help7",
	"pictureviewer.help8",
	"pictureviewer.help9",
	"pictureviewer.resize.color_average",
	"pictureviewer.resize.none",
	"pictureviewer.resize.simple",
	"pictureviewer.scaling",
	"pictureviewer.show",
	"pictureviewer.slide_time",
	"pictureviewer.slideshow",
	"pictureviewer.sortorder",
	"pictureviewer.sortorder.date",
	"pictureviewer.sortorder.filename",
	"ping.ok",
	"ping.protocol",
	"ping.socket",
	"ping.unreachable",
	"pinprotection.head",
	"pinprotection.wrongcode",
	"plugins.result",
	"rclock.lockmsg",
	"rclock.menueadd",
	"rclock.title",
	"rclock.unlockmsg",
	"recdirchooser.free",
	"recdirchooser.not_mounted",
	"recdirchooser.server_down",
	"recdirchooser.user_dir",
	"recordingmenu.apids",
	"recordingmenu.apids_ac3",
	"recordingmenu.apids_alt",
	"recordingmenu.apids_std",
	"recordingmenu.choose_direct_rec_dir",
	"recordingmenu.defdir",
	"recordingmenu.dir_permissions",
	"recordingmenu.dir_permissions_hint",
	"recordingmenu.epg_for_filename",
	"recordingmenu.file",
	"recordingmenu.filename_template",
	"recordingmenu.filename_template_hint",
	"recordingmenu.filesettings",
	"recordingmenu.head",
	"recordingmenu.help",
	"recordingmenu.no_scart",
	"recordingmenu.off",
	"recordingmenu.record_in_spts_mode",
	"recordingmenu.recording_type",
	"recordingmenu.ringbuffers",
	"recordingmenu.server",
	"recordingmenu.server_ip",
	"recordingmenu.server_mac",
	"recordingmenu.server_port",
	"recordingmenu.server_wakeup",
	"recordingmenu.setupnow",
	"recordingmenu.splitsize",
	"recordingmenu.stopplayback",
	"recordingmenu.stopsectionsd",
	"recordingmenu.stream_subtitle_pid",
	"recordingmenu.stream_vtxt_pid",
	"recordingmenu.use_fdatasync",
	"recordingmenu.use_o_sync",
	"recordingmenu.vcr",
	"recordingmenu.zap_on_announce",
	"recordtimer.announce",
	"repeatblocker.hint_1",
	"repeatblocker.hint_2",
	"satsetup.diseqc",
	"satsetup.diseqc10",
	"satsetup.diseqc11",
	"satsetup.diseqc12",
	"satsetup.diseqcrepeat",
	"satsetup.extended",
	"satsetup.extended_motor",
	"satsetup.minidiseqc",
	"satsetup.motorcontrol",
	"satsetup.nodiseqc",
	"satsetup.satellite",
	"satsetup.savesettingsnow",
	"satsetup.smatvremote",
	"scantp.fec",
	"scantp.fec_1_2",
	"scantp.fec_2_3",
	"scantp.fec_3_4",
	"scantp.fec_5_6",
	"scantp.fec_7_8",
	"scantp.freq",
	"scantp.pol",
	"scantp.pol_h",
	"scantp.pol_v",
	"scantp.rate",
	"scantp.scan",
	"scantp.scanmode",
	"scants.abort_body",
	"scants.abort_header",
	"scants.actcable",
	"scants.actsatellite",
	"scants.bouquet",
	"scants.bouquet_create",
	"scants.bouquet_erase",
	"scants.bouquet_leave",
	"scants.bouquet_satellite",
	"scants.bouquet_update",
	"scants.channel",
	"scants.failed",
	"scants.finished",
	"scants.freqdata",
	"scants.head",
	"scants.numberofdataservices",
	"scants.numberofradioservices",
	"scants.numberoftotalservices",
	"scants.numberoftvservices",
	"scants.provider",
	"scants.startnow",
	"scants.transponders",
	"screensetup.lowerright",
	"screensetup.upperleft",
	"sectionsd.scanmode",
	"servicemenu.chan_epg_stat",
	"servicemenu.chan_epg_stat_epg_stat",
	"servicemenu.getplugins",
	"servicemenu.getplugins_hint",
	"servicemenu.head",
	"servicemenu.imageinfo",
	"servicemenu.reload",
	"servicemenu.reload_hint",
	"servicemenu.restart",
	"servicemenu.restart_failed",
	"servicemenu.restart_hint",
	"servicemenu.restart_refused_recording",
	"servicemenu.scants",
	"servicemenu.ucodecheck",
	"servicemenu.update",
	"settings.help",
	"settings.missingoptionsconffile",
	"settings.noconffile",
	"settings.pos_bottom_left",
	"settings.pos_bottom_right",
	"settings.pos_default_center",
	"settings.pos_higher_center",
	"settings.pos_infobar",
	"settings.pos_off",
	"settings.pos_top_left",
	"settings.pos_top_right",
	"shutdown.recoding_query",
	"shutdowntimer.announce",
	"sleeptimerbox.announce",
	"sleeptimerbox.hint1",
	"sleeptimerbox.hint2",
	"sleeptimerbox.title",
	"streamfeatures.head",
	"streaminfo.aratio",
	"streaminfo.aratio_unknown",
	"streaminfo.audiotype",
	"streaminfo.audiotype_unknown",
	"streaminfo.bitrate",
	"streaminfo.close",
	"streaminfo.framerate",
	"streaminfo.framerate_unknown",
	"streaminfo.head",
	"streaminfo.maximize",
	"streaminfo.not_available",
	"streaminfo.resize",
	"streaminfo.resolution",
	"streaminfo.signal",
	"streaming.buffer_overflow",
	"streaming.busy",
	"streaming.dir_not_writable",
	"streaming.out_of_memory",
	"streaming.success",
	"streaming.write_error",
	"streaming.write_error_open",
	"streamingmenu.352x288",
	"streamingmenu.352x576",
	"streamingmenu.480x576",
	"streamingmenu.704x576",
	"streamingmenu.filebrowser_allow_multiselect",
	"streamingmenu.head",
	"streamingmenu.mpeg1",
	"streamingmenu.mpeg2",
	"streamingmenu.off",
	"streamingmenu.on",
	"streamingmenu.server_ip",
	"streamingmenu.server_port",
	"streamingmenu.streaming_audiorate",
	"streamingmenu.streaming_buffer_segment_size",
	"streamingmenu.streaming_buffer_segment_size_hint1",
	"streamingmenu.streaming_buffer_segment_size_hint2",
	"streamingmenu.streaming_force_avi_rawaudio",
	"streamingmenu.streaming_force_transcode_video",
	"streamingmenu.streaming_resolution",
	"streamingmenu.streaming_server_cddrive",
	"streamingmenu.streaming_server_startdir",
	"streamingmenu.streaming_show_tv_in_browser",
	"streamingmenu.streaming_transcode_audio",
	"streamingmenu.streaming_transcode_video_codec",
	"streamingmenu.streaming_type",
	"streamingmenu.streaming_use_buffer",
	"streamingmenu.streaming_videorate",
	"streamingserver.noconnect",
	"stringinput.caps",
	"stringinput.clear",
	"timer.eventrecord.msg",
	"timer.eventrecord.title",
	"timer.eventtimed.msg",
	"timer.eventtimed.title",
	"timerbar.channelswitch",
	"timerbar.recordevent",
	"timerlist.alarmtime",
	"timerlist.apids",
	"timerlist.apids_dflt",
	"timerlist.bouquetselect",
	"timerlist.channel",
	"timerlist.channelselect",
	"timerlist.delete",
	"timerlist.menumodify",
	"timerlist.menunew",
	"timerlist.message",
	"timerlist.moderadio",
	"timerlist.modeselect",
	"timerlist.modetv",
	"timerlist.modify",
	"timerlist.name",
	"timerlist.new",
	"timerlist.overlapping_timer1",
	"timerlist.overlapping_timer2",
	"timerlist.overlapping_timer3",
	"timerlist.plugin",
	"timerlist.program.unknown",
	"timerlist.recording_dir",
	"timerlist.reload",
	"timerlist.repeat",
	"timerlist.repeat.biweekly",
	"timerlist.repeat.byeventdescription",
	"timerlist.repeat.daily",
	"timerlist.repeat.fourweekly",
	"timerlist.repeat.friday",
	"timerlist.repeat.monday",
	"timerlist.repeat.monthly",
	"timerlist.repeat.once",
	"timerlist.repeat.saturday",
	"timerlist.repeat.sunday",
	"timerlist.repeat.thursday",
	"timerlist.repeat.tuesday",
	"timerlist.repeat.unknown",
	"timerlist.repeat.wednesday",
	"timerlist.repeat.weekdays",
	"timerlist.repeat.weekly",
	"timerlist.repeatcount",
	"timerlist.repeatcount.help1",
	"timerlist.repeatcount.help2",
	"timerlist.save",
	"timerlist.standby",
	"timerlist.standby.off",
	"timerlist.standby.on",
	"timerlist.stoptime",
	"timerlist.type",
	"timerlist.type.execplugin",
	"timerlist.type.nextprogram",
	"timerlist.type.record",
	"timerlist.type.remind",
	"timerlist.type.shutdown",
	"timerlist.type.sleeptimer",
	"timerlist.type.standby",
	"timerlist.type.unknown",
	"timerlist.type.zapto",
	"timerlist.weekdays",
	"timerlist.weekdays.hint_1",
	"timerlist.weekdays.hint_2",
	"timersettings.record_safety_time_after",
	"timersettings.record_safety_time_after.hint_1",
	"timersettings.record_safety_time_after.hint_2",
	"timersettings.record_safety_time_before",
	"timersettings.record_safety_time_before.hint_1",
	"timersettings.record_safety_time_before.hint_2",
	"timersettings.separator",
	"timing.chanlist",
	"timing.epg",
	"timing.filebrowser",
	"timing.head",
	"timing.hint_1",
	"timing.hint_2",
	"timing.infobar",
	"timing.infobar_movieplayer",
	"timing.infobar_radio",
	"timing.menu",
	"timing.numericzap",
	"ucodecheck.avia500",
	"ucodecheck.avia600",
	"ucodecheck.cam-alpha",
	"ucodecheck.head",
	"ucodecheck.ucode",
	"ucodes.failure",
	"upnpbrowser.head",
	"upnpbrowser.noservers",
	"upnpbrowser.rescan",
	"upnpbrowser.scanning",
	"usermenu.button_blue",
	"usermenu.button_green",
	"usermenu.button_red",
	"usermenu.button_yellow",
	"usermenu.head",
	"usermenu.item_bar",
	"usermenu.item_epg_misc",
	"usermenu.item_none",
	"usermenu.item_vtxt",
	"usermenu.name",
	"videomenu.csync",
	"videomenu.head",
	"videomenu.osd",
	"videomenu.rgb_centering",
	"videomenu.screensetup",
	"videomenu.tv-scart",
	"videomenu.vcr-scart",
	"videomenu.vcrsignal",
	"videomenu.vcrsignal_composite",
	"videomenu.vcrsignal_svideo",
	"videomenu.vcrswitch",
	"videomenu.videoformat",
	"videomenu.videoformat_169",
	"videomenu.videoformat_43",
	"videomenu.videoformat_431",
	"videomenu.videoformat_autodetect",
	"videomenu.videosignal",
	"videomenu.videosignal_composite",
	"videomenu.videosignal_rgb",
	"videomenu.videosignal_svideo",
	"videomenu.videosignal_yuv_c",
	"videomenu.videosignal_yuv_v",
	"zapit.scantype",
	"zapit.scantype.all",
	"zapit.scantype.radio",
	"zapit.scantype.tv",
	"zapit.scantype.tvradio",
	"zaptotimer.announce",
};
#endif
