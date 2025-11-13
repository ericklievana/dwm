#include <X11/XF86keysym.h>
#include "commands.h"
#include "keymaps.h"

#define STATUSBAR "dwmblocks"

/* appearance */
static unsigned int borderpx  = 5;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
static char font[]            = "monospace:size=10";
static const char *fonts[]          = { font };
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
static const char *tags[] = { "󰎦", "󰎩", "󰎬", "󰎮", "󰎰", "󰎵", "󰎸", "󰎻", "󰎾", };
static const char *alttags[] = { "󰎤", "󰎧", "󰎪", "󰎭", "󰎱", "󰎳", "󰎶", "󰎹", "󰎼", };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "steam",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 60;  /* refresh rate (per second) for client move/resize */


/* key definitions */

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
  { "font",               STRING,  &font },
  { "normbgcolor",        STRING,  &normbgcolor },
  { "normbordercolor",    STRING,  &normbordercolor },
  { "normfgcolor",        STRING,  &normfgcolor },
  { "selbgcolor",         STRING,  &selbgcolor },
  { "selbordercolor",     STRING,  &selbordercolor },
  { "selfgcolor",         STRING,  &selfgcolor },
  { "borderpx",          	INTEGER, &borderpx },
  { "snap",          		INTEGER, &snap },
  { "showbar",          	INTEGER, &showbar },
  { "topbar",          	INTEGER, &topbar },
  { "nmaster",          	INTEGER, &nmaster },
  { "resizehints",       	INTEGER, &resizehints },
  { "mfact",      	 	FLOAT,   &mfact },
};


