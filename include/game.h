typedef struct Creature Creature;
typedef struct ViewState ViewState;

enum {
	CompassNorth,
	CompassNorthEast,
	CompassEast,
	CompassSouthEast,
	CompassSouth,
	CompassSouthWest,
	CompassWest,
	CompassNorthWest
};

enum {
	InputAppQuit,
	InputUIUp,
	InputUIRight,
	InputUIDown,
	InputUILeft,
	InputUISubmit,
	InputUICancel,
	InputMoveNorth,
	InputMoveEast,
	InputMoveSouth,
	InputMoveWest,
	NINPUT
};

enum {
	SaveTypeMain,
	SaveTypeAuto,
	SaveTypeBackup
};

enum {
	EngineAnimRate = 500,
	EngineDisplayWidth = 80,
	EngineDisplayHeight = 26,
	EngineDisplayArea = EngineDisplayWidth * EngineDisplayHeight,
	MaxViewStates = 8,
	MaxSaveIndex = 8
};

struct Creature {
	Point position;
};

struct ViewState {
	boolean fullscreen; /* true stops lower views from drawing */
	boolean disableturnprocess; /* false processes the game turns before update */
	boolean disableworldanim; /* false allows the game world to animate */
	boolean disableworlddraw; /* false draws the game world before view */
	void (*animate)(void);
	void (*close)(void);
	void (*draw)(void);
	void (*open)(void);
	void (*update)(void); /* mandatory */
};

extern const ViewState ViewMainMenu;
extern const ViewState ViewSandbox;

extern int currentsaveindex;
extern Creature player;

/* compass */
flag compassanticlockwise(flag);
flag compassanticlockwisecardinal(flag);
flag compassanticlockwiseordinal(flag);
flag compassclockwise(flag);
flag compassclockwisecardinal(flag);
flag compassclockwiseordinal(flag);
boolean compassiscardinal(flag);
boolean compassisopposite(flag, flag);
boolean compassisordinal(flag);
flag compassopposite(flag);
Point compasstopoint(flag);

/* creature */
boolean creaturecanmove(Creature*, flag);
void creaturemove(Creature*, flag);

/* draw */
// void drawfill();
// void drawlabel(); // single line, cut off, optional centering
// void drawnineslice();
// void drawoutline();
// void drawoverlay(); // multiplies colors with alphas, does not include chars
// void drawtext(); // in area, wraps appropriately

// void drawgameworld();

/* engine */
void enginepopview(void);
void enginepushview(ViewState);
void enginesetview(ViewState);
void enginestart(void);
void enginestop(void);

/* game */
void gamelaunch(void);
void gameloadsave(int, flag);
void gamenewsave(int);
void gamesave(flag);
// gamenextturn();

/* input */
boolean inputhasactive(void);
boolean inputispressed(flag);
void inputupdate(void);
