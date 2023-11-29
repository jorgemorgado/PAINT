/***
* GLOBAL.H
* Definições gerais do programa PAINT.C
*/


#define BYTE                    unsigned char
#define BOOLEAN                 int
#define TRUE                    1
#define FALSE                   0

#define ICON_POINT              0
#define ICON_LINE               1
#define ICON_BOX                2
#define ICON_CIRCLE             3
#define ICON_ELLIPSE            4
#define ICON_ARC                5

#define ICON_FILL               6
#define ICON_COPYVIEW           7
#define ICON_XORVIEW            8
#define ICON_UNDO               9
#define ICON_LOAD               10
#define ICON_SAVE               11
#define ICON_EXIT               12


//-----------------------------------------------------------------------------
//---------------------------------------------------------- Variáveis públicas

int nrClick = 0;
int xMouse, yMouse, xLastMouse, yLastMouse;
BYTE nToolboxOp = ICON_POINT;
BOOLEAN mouseDrag = FALSE;

#define MAX_COORDS              4

int *auxCoord[ MAX_COORDS ];

//-----------------------------------------------------------------------------
//--------------------------------------------- Estruturas e uniões do programa

struct t_point {
    int x, y;
};

struct t_line {
    int x1, y1, x2, y2;
};

struct t_box {
    int x1, y1, x2, y2;
};

struct t_circle {
    int x, y, radius;
};

struct t_ellipse {
    int x, y, xradius, yradius;
};

typedef struct t_point   POINT;
typedef struct t_line    LINE;
typedef struct t_box     BOX;
typedef struct t_circle  CIRCLE;
typedef struct t_ellipse ELLIPSE;

union t_command {
    POINT   *ptrPoint;
    LINE    *ptrLine;
    BOX     *ptrBox;
    CIRCLE  *ptrCircle;
    ELLIPSE *ptrEllipse;
};

typedef union t_command CMDTYPE;

// Lista genérica para todas as figuras. As figuras serão armazenados na lista
// exactamente na mesma ordem com que foram sendo desenhados pelo utilizador.
struct t_list {
    struct t_list *ptrPrev;       // Apontador para a figura anteror
    struct t_list *ptrNext;       // Apontador para a próxima figura
    CMDTYPE *ptrCmdType;          // Apontador para o tipo de figura
    char    *ptrCmdName;          // Apontador para a string comando
};

typedef struct t_list LIST;

LIST *ptrFirst;                   // Apontador para o primeiro elemnto da lista
LIST *ptrLast;                    // Apontador para o último elemnto da lista

//-----------------------------------------------------------------------------
//------------------------------------------- Protótipos das funções utilizadas

// Fonte DRAW.C
void draw_point  ( int, int );
void draw_line   ( int, int, int, int );
void draw_box    ( int, int, int, int );
void draw_circle ( int, int, int );
void draw_ellipse( int, int, int, int );
void first_click ( void );
void drag_figure ( void );
void second_click( void );

// Fonte SAVE.C
void save_command( void );
void save        ( void );

// Fonte TOOLBOX.C
void display_toolbox( void );
void click_toolbox  ( BOOLEAN * );

// Fonte VIEW.C
void view( int );

// Fonte UNDO.C
void undo( void );

// Fonte LOAD.C
void load( void );
