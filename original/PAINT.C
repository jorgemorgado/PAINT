/***
*  PAINT.C
*  Programa de desenho
*  Jorge Alexandre Morgado, Borland C, CopyRight 1994
*/


#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <graphics.h>

#include "global.h"
#include "mouse.c"
#include "save.c"
#include "draw.c"
#include "view.c"
#include "undo.c"
#include "load.c"
#include "toolbox.c"


void main( void )
{
   int gdriver = DETECT, gmode, n;
   BOOLEAN lExit = FALSE;
   void ( *func_click[ 2 ] )( void );

   clrscr();

   if( !mouse_Status() )                           // Verifica se existe mouse
   {
      printf( "\nErro: n„o h  rato\n" );
      exit( 1 );
   }

   initgraph( &gdriver, &gmode, "f:\\borlandc\\bgi" );  // Inicia modo gr fico

   if( graphresult() != grOk )                     // Verifica se ocorreu erro
   {
      printf( "\nErro: inicializa‡„o do modo gr fico\n" );
      exit( 1 );
   }

   for( n = 0; n < MAX_COORDS; n++ )                      // Aloca espa‡o para
      auxCoord[ n ] = ( int * )malloc( sizeof( int ) );   // coords  auxilares

   func_click[ 0 ] = first_click;      // Define as  fun‡”es a  ser executadas
   func_click[ 1 ] = second_click;     // quando o bot„o do  mouse ‚ "clicado"

   display_toolbox();                                       // Exibe a toolbox
   mouse_ShowCursor();                              // Exibe o cursor do mouse
   setwritemode( XOR_PUT );             // Define o modo de escrita em XOR_PUT

   do
   {
      xMouse = mouse_GetXPos();                  // Obt‚m a posi‡„o X do mouse
      yMouse = mouse_GetYPos();                  // Obt‚m a posi‡„o Y do mouse

      if( mouse_ButtonStatus() == MB_RIGHT && yMouse > 53 * 8 - 1 )
	 click_toolbox( &lExit );         // Se mouse-click foi dentro do menu
      else if( mouse_ButtonStatus() == MB_LEFT )
	 ( *func_click[ nrClick ] )();
      else if( mouseDrag )
	 drag_figure();
   }
   while( !lExit );

   while( ptrFirst != NULL )                   // Elimina  a  lista  existente
      undo();                                  // para libertar toda a mem¢ria

   closegraph();                                       // Fecha o modo gr fico
}
