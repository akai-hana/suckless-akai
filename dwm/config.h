/* akai's custom config */

/* appearance */
// windows
static const unsigned int borderpx = 0;        /* border pixel of windows */
static const unsigned int snap     = 32;       /* snap pixel */
static const int showbar           = 1;        /* 0 means no bar */
static const int topbar            = 0;        /* 0 means bottom bar */

// font
static const char *fonts[]         = { "FiraCode Nerd Font Mono Ret:style=Regular:size=10" };
static const char dmenufont[]      = { "FiraCode Nerd Font Mono Ret:style=Regular:size=10" };

// colorscheme
static const char col_gray1[]      = "#0f1015";
static const char col_gray2[]      = "#444444";
static const char col_gray3[]      = "#bbbbbb";
static const char col_gray4[]      = "#eeeeee";
static const char col_cyan[]       = "#ac3232"; /* focused color */
static const char *colors[][3]     = {
       /*               fg         bg         border   */
       [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
       [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
// workspace indicators
static const char *tags[] = { "m", "a", "t", "i", "a", "s" };

// workspace redirects
static const Rule rules[] = {
        /* class            instance    title  tags mask  isfloating  monitor */
        { "firefox",        NULL,       NULL,  1 << 0,    0,          -1 },
        { "equibop",        NULL,       NULL,  1 << 1,    0,          -1 },
        { "prismlauncher",  NULL,       NULL,  1 << 2,    0,          -1 },
        { "Emacs",          NULL,       NULL,  1 << 4,    0,          -1 },
        { "java",           NULL,       NULL,  1 << 4,    0,          -1 },
        { "corectrl",       NULL,       NULL,  1 << 5,    0,          -1 },
        { "qbittorrent",    NULL,       NULL,  1 << 5,    0,          -1 },
};

/* layout(s) */
static const float mfact        = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "/home/akai/Apps/ghostty.AppImage", NULL };

// custom placeholders
static const char *browser[]   = { "sh", "-c", "~/scripts/firefox.sh", NULL };
static const char *discord[]   = { "sh", "-c", "~/scripts/discord.sh", NULL };
static const char *minecraft[] = { "sh", "-c", "prismlauncher", NULL };
static const char *music[]     = { "sh", "-c", "~/scripts/music.sh", NULL };
static const char *ddnet[]     = { "sh", "-c", "~/scripts/ddnet.sh", NULL };
static const char *osu[]       = { "sh", "-c", "~/scripts/osu.sh", NULL };

/* bindkeys */
static const Key keys[] = {
	// workspaces (6)
	TAGKEYS( XK_1, 0)
	TAGKEYS( XK_2, 1)
	TAGKEYS( XK_3, 2)
	TAGKEYS( XK_q, 3)
	TAGKEYS( XK_w, 4)
	TAGKEYS( XK_e, 5)

	// important dwm stuff
	{ MODKEY,             XK_r,        spawn,            {.v = dmenucmd } },
	{ MODKEY|ShiftMask,   XK_Return,   quit,             {0} },

	{ MODKEY,             XK_a,        spawn,  	     {.v = browser } },
	{ MODKEY,             XK_s,        spawn,    	     {.v = discord } },
	{ MODKEY,             XK_d,        spawn,  	     {.v = termcmd } },
	{ MODKEY,             XK_f,        spawn,  	     {.v = music } },
	{ MODKEY,             XK_g,        spawn,    	     {.v = minecraft } },
	{ MODKEY,             XK_z,        spawn,    	     {.v = ddnet } },
	{ MODKEY,             XK_x,        spawn,    	     {.v = osu } },

	{ MODKEY,             XK_b,        togglebar,        {0} },
	{ MODKEY,             XK_j,        focusstack,       {.i = +1 } },
	{ MODKEY,             XK_k,        focusstack,       {.i = -1 } },

	/* remove inc/dec master: i don't use it, takes up keybinding slots */
	// { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	// { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	
	// window control
	{ MODKEY,             XK_h,        setmfact,         {.f = -0.05} },
	{ MODKEY,             XK_l,        setmfact,         {.f = +0.05} },
	{ MODKEY,             XK_Return,   zoom,             {0} },
	{ MODKEY,             XK_Tab,      view,             {0} },
	{ MODKEY|ShiftMask,   XK_c,        killclient,       {0} },
	{ MODKEY,             XK_4,        setlayout,        {.v = &layouts[0]} },
	{ MODKEY,             XK_5,        setlayout,        {.v = &layouts[1]} },
	{ MODKEY,             XK_m,        setlayout,        {.v = &layouts[2]} },
	{ MODKEY,             XK_space,    setlayout,        {0} },
	{ MODKEY|ShiftMask,   XK_space,    togglefloating,   {0} },
	{ MODKEY,             XK_0,        view,             {.ui = ~0 } },
	{ MODKEY|ShiftMask,   XK_0,        tag,              {.ui = ~0 } },
	{ MODKEY,             XK_comma,    focusmon,         {.i = -1 } },
	{ MODKEY,             XK_period,   focusmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,   XK_comma,    tagmon,           {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_period,   tagmon,           {.i = +1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click           eventmask button     function          argument */
	{ ClkLtSymbol,     0,        Button1,   setlayout,        {0} },
	{ ClkLtSymbol,     0,        Button3,   setlayout,        {.v = &layouts[2]} },
	{ ClkWinTitle,     0,        Button2,   zoom,             {0} },
	{ ClkStatusText,   0,        Button2,   spawn,            {.v = termcmd } },
	{ ClkClientWin,    MODKEY,   Button1,   movemouse,        {0} },
	{ ClkClientWin,    MODKEY,   Button2,   togglefloating,   {0} },
	{ ClkClientWin,    MODKEY,   Button3,   resizemouse,      {0} },
	{ ClkTagBar,       0,        Button1,   view,             {0} },
	{ ClkTagBar,       0,        Button3,   toggleview,       {0} },
	{ ClkTagBar,       MODKEY,   Button1,   tag,              {0} },
	{ ClkTagBar,       MODKEY,   Button3,   toggletag,        {0} },
};
