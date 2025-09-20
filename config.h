#include <X11/XF86keysym.h>
#include <colors.h>

//GENERAL
// Set modifier key
#define MODKEY Mod4Mask
// Set border width in pixels
static const unsigned int borderpx = 5;
// Set snap pixel
static const unsigned int snap = 32;
// Set if the status bar is show or not
static const int showbar = 1;
// Set the position of the bar 1 = top, 0 = bottom
static const int topbar = 1;
// Set to center or not the elements of the status bar
static const int splitstatus = 1;
// Set the char to delimiter the center elements from the right elements
static const char *splitdelim = ";";
// Set force focus in the fullscreen window
static const int lockfullscreen = 1;
// Set the refresh rate per second for client move/resize
static const int refreshrate = 60;
// Set the fonts
static const char *fonts[] = {
  "Code New Roman:size=24:antialias=true:autohint=true",
  "Symbols Nerd Font Mono:size=24:antialias=true:autohint=true",
};
// Set the color of the schemes
static const char *colors[][3] = {
  [SchemeNorm] = { normalWhite, normalBlack, normalBlack },
  [SchemeSel]  = { normalRed, normalBlack,  normalRed  },
};
// Set the symbols used for the tags
static const char *tags[] = { "󰲡", "󰲣", "󰲥", "󰲧", "󰲩", "󰲫", "󰲭", "󰲯", "󰲱", };
static const char *alttags[] = { "󰲠", "󰲢", "󰲤", "󰲦", "󰲨", "󰲪", "󰲬", "󰲮", "󰲰", };
// Set program specific rules
// Class-Instance-Title-Tagsmask-Floating-Monitor
static const Rule rules[] = {
  { "Gimp",     NULL,       NULL,       0,            1,           -1 },
  { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

// LAYOUTS
static const Layout layouts[] = {
  { "[]=",      tile },
  { "[M]",      monocle },
  { "|M|",      centeredmaster },
  { ">M>",      centeredfloatingmaster },
  { "><>",      NULL },
};
// TILE LAYOUT
// Set the percentage of the screen the master window takes
static const float mfact = 0.55;
// Set the number of clients in the master area
static const int nmaster = 1;
// Set if size hints are respected in resizals
static const int resizehints = 1;

// COMMANDS
static const char *dmenu[] = { "dmenu_run", NULL };
static const char *terminal[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

// KEYMAPS
// Key Definitions
#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


static const Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY,                       XK_p,      spawn,          {.v = dmenu } },
  { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = terminal } },
  { MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
  { MODKEY,                       XK_b,      togglebar,      {0} },
  { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
  { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY,                       XK_Return, zoom,           {0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
  { MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
  { MODKEY,                       XK_space,  setlayout,      {0} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
  { MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  TAGKEYS(                        XK_6,                      5)
  TAGKEYS(                        XK_7,                      6)
  TAGKEYS(                        XK_8,                      7)
  TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = terminal } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

