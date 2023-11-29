/***
*  DRAW.C
*  Desenho das v rias figuras (pontos, linhas, caixas, etc.).
*/


/***
*  draw_point( int x, int y )
*  Desenha um pixel no ecran nas coordenadas (x,y) e na cor actual.
*/
void draw_point( int x, int y )
{
   putpixel( x, y, getcolor() );
}

/***
*  draw_line( int x1, int y1, int x2, int y2 )
*  Desenha uma linha desde a coordenada (x1,y1) at‚ … coordenada (x2,y2).
*/
void draw_line( int x1, int y1, int x2, int y2 )
{
   line( x1, y1, x2, y2 );
}

/***
*  draw_box( int x1, int y1, int x2, int y2 )
*  Desenha uma caixa desde a coordenada (x1,y1) at‚ … coordenada (x2,y2).
*/
void draw_box( int x1, int y1, int x2, int y2 )
{
   rectangle( x1, y1, x2, y2 );
}

/***
*  draw_circle( int xcenter, int ycenter, int radius )
*  Desenha um c¡rculo com centro na coordenada (xcenter,ycenter) e raio
*  radius.
*/
void draw_circle( int xcenter, int ycenter, int radius )
{
   int nX = 0, nY = radius, nD = 3 - ( 2 * radius );
   int xcp, xcm, ycp, ycm, yxcp, yxcm, xycp, xycm;

   while( nX < nY )
   {
      xcp  = xcenter + nX;                 ycp  = ycenter + nY;
      xcm  = xcenter - nX;                 ycm  = ycenter - nY;
      xycp = xcenter + nY;                 yxcp = ycenter + nX;
      xycm = xcenter - nY;                 yxcm = ycenter - nX;

      line( xcp, ycp, xcp, ycp );          line( xycp, yxcp, xycp, yxcp );
      line( xcp, ycm, xcp, ycm );          line( xycp, yxcm, xycp, yxcm );
      line( xcm, ycp, xcm, ycp );          line( xycm, yxcp, xycm, yxcp );
      line( xcm, ycm, xcm, ycm );          line( xycm, yxcm, xycm, yxcm );

      if( nD < 0 )
	 nD += 4 * nX + 6;
      else
      {
	 nD += 4 * ( nX - nY ) + 10;
	 nY--;
      }

      nX++;
   }
}

/***
*  draw_ellipse( int xcenter, int ycenter, int xradius, int yradius )
*  Desenha um elipse completa com centro coordenada (xcenter,ycenter). Os
*  parƒmeteros xradius e yradius representam, respectivamente, os raios
*  horizontal e vertical.
*/
void draw_ellipse( int xcenter, int ycenter, int xradius, int yradius )
{
   int xold = xcenter, yold = ycenter + yradius;
   float n, pi = 3.1415;

   for( n = 0; n < 2 * pi; n += .25 )
   {
      line( xold, yold,
	    xcenter + xradius * sin( n ), ycenter + yradius * cos( n ) );

      xold = xcenter + xradius * sin( n );
      yold = ycenter + yradius * cos( n );
   }

   line( xold, yold, xcenter, ycenter + yradius );
}

/***
*  Esta ‚ a fun‡„o ellipse que ‚ oferecida pela Borland em GRAPHICS.H
   ellipse( xcenter, ycenter, 0, 360, xradius, yradius );
*/

/***
*  Esta fun‡„o desenha uma elipse mas com algumas falhas (‚ muito lenta)
   float n, pi = 3.141519;

   for( n = 0; n < 2 * pi; n += .01 )
      line( xcenter + xradius * sin( n ), ycenter + yradius * cos( n ),
	    xcenter + xradius * sin( n ), ycenter + yradius * cos( n ) );
*/

/***
*  Esta fun‡„o desenha uma elipse mas n„o funciona muito bem em alguns casos
   int l, a, b, xx;
   int xp, yp, xpold, ypold;

   a = sqrt( pow( abs( y - ycenter ), 2 ) + a*a );             // 100;
   l = abs( x - xcenter );                                     // 40;
   b = l - a;
   xpold = 0;
   ypold = a;

   for( xx = 0; l > 0 && ( l*l - xx*xx ) >= 0 && xx <= l; xx++ )
   {
      xp = xx * b / l;
      yp = a * ( int )sqrt( l*l - xx*xx ) / l;

      line( xcenter + xpold, ycenter + ypold, xcenter + xp, ycenter + yp );
      line( xcenter + xpold, ycenter - ypold, xcenter + xp, ycenter - yp );
      line( xcenter - xpold, ycenter - ypold, xcenter - xp, ycenter - yp );
      line( xcenter - xpold, ycenter + ypold, xcenter - xp, ycenter + yp );

      xpold = xp;
      ypold = yp;
   }
*/


/***
*  mark_coord( void )
*  Actualiza as coordenadas para a posi‡„o actual do rato. A fun‡„o actualiza
*  ainda as vari veis xLastMouse e yLastMouse, que representam a £ltima
*  posi‡„o onde o rato foi "clicado". Finalmente ‚ incrementado o contador de
*  "cliques" (vari vel nrClick), visto que esta fun‡„o s¢ ‚ chamada em alguns
*  casos quando o utilizador carrega num dos bot”es do rato (normalmente
*  quando para desenha uma figura carrega a primeira vez).
*/
void mark_coord( void )
{
   *auxCoord[ 0 ] = xLastMouse = xMouse;
   *auxCoord[ 1 ] = yLastMouse = yMouse;
   nrClick++;
}


/***
*  draw_figure( int x, int y )
*  Chama as v rias fun‡”es que desenham as figuras dependendo do icon
*  seleccionado na toolbar. Os parƒmeteros x e y s„o valores utilizados no
*  desenho das v rias figuras.
*/
void draw_figure( int x, int y )
{
   switch( nToolboxOp )
   {
      case ICON_LINE:
	 draw_line( *auxCoord[ 0 ], *auxCoord[ 1 ], x, y );
	 break;
      case ICON_BOX:
	 draw_box( *auxCoord[ 0 ], *auxCoord[ 1 ], x, y );
	 break;
      case ICON_CIRCLE:
	 *auxCoord[ 2 ] = ( int )sqrt( pow( *auxCoord[ 0 ] - x, 2 ) + pow( *auxCoord[ 1 ] - y, 2 ) );
	 draw_circle( *auxCoord[ 0 ], *auxCoord[ 1 ], *auxCoord[ 2 ] );
	 break;
      case ICON_ELLIPSE:
	 *auxCoord[ 2 ] = abs( x - *auxCoord[ 0 ] );
	 *auxCoord[ 3 ] = abs( y - *auxCoord[ 1 ] );
	 draw_ellipse( *auxCoord[ 0 ], *auxCoord[ 1 ], *auxCoord[ 2 ], *auxCoord[ 3 ] );
	 break;
      default:
	 break;
   }
}


/***
*  first_click( void )
*  Esta fun‡„o ‚ chamada quando o utilizador carrega no rato pela primeira
*  vez para desenhar um determinada figura. A fun‡„o procede de acordo com a
*  figura a ser desenhada. Por exemplo, se o utilizador deseja simplesmente
*  desenhar um ponto (pixel), ent„o bastar  um £nico click. O mesmo j  n„o
*  acontece com outras figuras, como por exemplo, as linhas, as caixas, etc.
*/
void first_click( void )
{
   switch( nToolboxOp )
   {
      case ICON_POINT:
	 mouse_HideCursor();
	 draw_point( ( *auxCoord[ 0 ] = xMouse ), ( *auxCoord[ 1 ] = yMouse ) );
	 save_command();
	 mouse_ShowCursor();
	 break;
      case ICON_LINE:
      case ICON_BOX:
      case ICON_CIRCLE:
      case ICON_ELLIPSE:
	 mark_coord();
	 mouseDrag = TRUE;     // Indica que vai come‡ar o arrastamento das figuras
	 break;
      default:
	 break;
   }

   while( mouse_ButtonStatus() == MB_LEFT );
}


/***
*  drag_figure( void )
*  Processa o arrastamento das figuras, como por exemplo, as linhas, as
*  caixas, os c¡rculos, as elipses, etc.
*/
void drag_figure( void )
{
   if( xLastMouse != xMouse || yLastMouse != yMouse )
   {
      mouse_HideCursor();
      draw_figure( xLastMouse, yLastMouse );
      draw_figure( ( *auxCoord[ 2 ] = xLastMouse = xMouse ), ( *auxCoord[ 3 ] = yLastMouse = yMouse ) );
      mouse_ShowCursor();
   }
}


/***
*  second_click( void )
*  Esta fun‡„o ‚ chamada quando o utilizador carrega no rato pela segunda vez
*  para desenhar um determinada figura. A fun‡„o procede de acordo com a
*  figura a ser desenhada. Por exemplo, se o utilizador deseja simplesmente
*  desenhar um ponto (pixel), ent„o bastar  um £nico click, e como tal esta
*  fun‡„o nunca ser  executada. No caso de outras figuras como as linhas ou as
*  caixas a fun‡„o ‚ chamada dando conta de que a figura foi desenhada, logo
*  deve ser incluida na base de dados.
*/
void second_click( void )
{
   switch( nToolboxOp )
   {
      case ICON_LINE:
      case ICON_BOX:
      case ICON_CIRCLE:
      case ICON_ELLIPSE:
	 save_command();
	 break;
      default:
	 break;
   }

   while( mouse_ButtonStatus() == MB_LEFT );
}
