/***
*  MOUSE.C
*  Livraria de fun��es para o mouse.
*/

#ifndef BOOLEAN
   #define BOOLEAN           int
#endif

#define MB_LEFT              1
#define MB_RIGHT             2

BOOLEAN  mouse_Status         ( void );
int      mouse_Buttons        ( void );
void     mouse_HideCursor     ( void );
void     mouse_ShowCursor     ( void );
int      mouse_GetXPos        ( void );
int      mouse_GetYPos        ( void );
int      mouse_ButtonStatus   ( void );

/***
*  NOTA: Fun��es n�o utilizadas
*/
/*
void     mouse_NewPosition    ( int, int );
int      mouse_ButtonPress    ( int );
int      mouse_CountPress     ( int );
int      mouse_LastXPress     ( int );
int      mouse_LastYPress     ( int );
int      mouse_ButtonRelease  ( int );
int      mouse_LastXRelease   ( int );
int      mouse_CountRelease   ( int );
int      mouse_LastYRelease   ( int );
void     mouse_XPosMinMax     ( int, int );
void     mouse_YPosMinMax     ( int, int );
void     mouse_SetGraphBlock  ( CURSORGRAPHIC *, int, int );
void     mouse_SetTextBlock   ( int, int, int );
int      mouse_XMotionCount   ( void );
int      mouse_YMotionCount   ( void );
void     mouse_LightPenEmulOn ( void );
void     mouse_LightPenEmulOff( void );
void     mouse_PixelRatio     ( int, int );
*/


BOOLEAN mouse_Status( void )
{
   struct REGPACK regs;

   regs.r_ax = 0x00;
   intr( 0x33, &regs );
   return( regs.r_ax != 0 );
}

int mouse_Buttons( void )
{
   struct REGPACK regs;

   regs.r_ax = 0x00;
   intr( 0x33, &regs );
   return( regs.r_bx );
}

void mouse_ShowCursor( void )
{
   struct REGPACK regs;

   regs.r_ax = 0x01;
   intr( 0x33, &regs );
}

void mouse_HideCursor( void )
{
   struct REGPACK regs;

   regs.r_ax = 0x02;
   intr( 0x33, &regs );
}

int mouse_GetXPos( void )
{
   struct REGPACK regs;

   regs.r_ax = 0x03;
   intr( 0x33, &regs );
   return( regs.r_cx );
}

int mouse_GetYPos( void )
{
   struct REGPACK regs;

   regs.r_ax = 0x03;
   intr( 0x33, &regs );
   return( regs.r_dx );
}

int mouse_ButtonStatus( void )
{
   struct REGPACK regs;

   regs.r_ax = 0x03;
   intr( 0x33, &regs );
   return( regs.r_bx );
}

/***
*  NOTA: Fun��es n�o utilizadas
*/
/*
void mouse_NewPosition( int NoUvX, int NoUvY )
{
   union REGS regs;

   regs.x.ax = 0x04;
   regs.x.cx = NoUvX;
   regs.x.dx = NoUvY;
   int86( 0x33, &regs, &regs );
}

int mouse_ButtonPress( int NoButton )
{
   union REGS regs;

   regs.x.ax = 0x05;
   regs.x.bx = NoButton;
   int86( 0x33, &regs, &regs);
   return( regs.x.ax );
}

int mouse_CountPress( int NoButton )
{
   union REGS regs;

   regs.x.ax = 0x05;
   regs.x.bx = NoButton;
   int86( 0x33, &regs, &regs );
   return( regs.x.bx );
}

int mouse_LastXPress( int NoButton )
{
   union REGS regs;

   regs.x.ax = 0x05;
   regs.x.bx = NoButton;
   int86( 0x33, &regs, &regs );
   return( regs.x.cx );
}

int mouse_LastYPress( int NoButton )
{
   union REGS regs;

   regs.x.ax = 0x05;
   regs.x.bx = NoButton;
   int86( 0x33, &regs, &regs );
   return( regs.x.dx );
}

int mouse_ButtonRelease( int NoButton )
{
   union REGS regs;

   regs.x.ax = 0x06;
   regs.x.bx = NoButton;
   int86( 0x33, &regs, &regs );
   return( regs.x.ax );
}

int mouse_CountRelease( int NoButton )
{
   union REGS regs;

   regs.x.ax = 0x06;
   regs.x.bx = NoButton;
   int86( 0x33, &regs, &regs );
   return( regs.x.bx );
}

int mouse_LastXRelease( int NoButton )
{
   union REGS regs;

   regs.x.ax = 0x06;
   regs.x.bx = NoButton;
   int86( 0x33, &regs, &regs );
   return( regs.x.cx );
}

int mouse_LastYRelease( int NoButton )
{
   union REGS regs;

   regs.x.ax = 0x06;
   regs.x.bx = NoButton;
   int86( 0x33, &regs, &regs );
   return( regs.x.dx );
}

void mouse_XPosMinMax( int MinX, int MaxX )
{
   struct REGPACK regs;

   regs.r_ax = 0x07;
   regs.r_cx = MinX;
   regs.r_dx = MaxX;
   intr( 0x33, &regs );
}

void mouse_YPosMinMax( int MinY, int MaxY )
{
   struct REGPACK regs;

   regs.r_ax = 0x08;
   regs.r_cx = MinY;
   regs.r_dx = MaxY;
   intr( 0x33, &regs );
}

void mouse_SetGraphBlock( CURSORGRAPHIC *Cursor, int X_Rel, int Y_Rel )
{
   struct REGPACK regs;
   struct SREGS segs;

   regs.r_ax = 0x09;
   regs.r_dx = FP_OFF( Cursor );  // FP_OFF( Cursor.mask )
   regs.r_ds = segs.cs;
   regs.r_es = segs.ds;
   regs.r_bx = X_Rel;
   regs.r_cx = Y_Rel;
   intr( 0x33, &regs );
}

void mouse_SetTextBlock( int MType, int MScreen, int MMask )
{
   union REGS regs;

   regs.x.ax = 10;
   regs.x.bx = MType;
   regs.x.cx = MScreen;
   regs.x.dx = MMask;
   int86( 0x33, &regs, &regs );
}

int mouse_XMotionCount( void )
{
   union REGS regs;

   regs.x.ax = 11;
   int86( 0x33, &regs, &regs );
   return( regs.x.cx );
}

int mouse_YMotionCount( void )
{
   union REGS regs;

   regs.x.ax = 11;
   int86( 0x33, &regs, &regs );
   return( regs.x.dx );
}

void mouse_LightPenEmulOn( void )
{
   union REGS regs;

   regs.x.ax = 13;
   int86( 0x33, &regs, &regs );
}

void mouse_LightPenEmulOff( void )
{
   union REGS regs;

   regs.x.ax = 14;
   int86( 0x33, &regs, &regs );
}

void mouse_PixelRatio( int MXRatio, int MYRatio )
{
   union REGS regs;

   regs.x.ax = 15;
   regs.x.cx = MXRatio;
   regs.x.dx = MYRatio;
   int86( 0x33, &regs, &regs );
}
*/
