/***
*  VIEW.C
*  Fun‡„o que exibe todas as figuras desenhadas (todos os elemntos da lista)
*  em modo COPY_PUT ou em modo XOR_PUT.
*/


/***
*  view( void )
*/
void view( int nViewMode )
{
   int nForeColor = getcolor();
   int nBackColor = getbkcolor();

   mouse_HideCursor();                            // Esconde o cursor do mouse
   setbkcolor( BLACK );                    // Activa o preto como cor de fundo
   cleardevice();                                             // Limpa o ecran

   if( ptrFirst != NULL )
   {
      LIST *ptr = ptrFirst;

      setwritemode( nViewMode );        // Activa o modo de escrita solicitado

      while( ptr != NULL )
      {
	 if( !strcmp( ptr -> ptrCmdName, "POINT" ) )
	    draw_point( ptr -> ptrCmdType -> ptrPoint -> x,
			ptr -> ptrCmdType -> ptrPoint -> y );
	 else if( !strcmp( ptr -> ptrCmdName, "LINE" ) )
	    draw_line( ptr -> ptrCmdType -> ptrLine -> x1,
		       ptr -> ptrCmdType -> ptrLine -> y1,
		       ptr -> ptrCmdType -> ptrLine -> x2,
		       ptr -> ptrCmdType -> ptrLine -> y2 );
	 else if( !strcmp( ptr -> ptrCmdName, "BOX" ) )
	    draw_box( ptr -> ptrCmdType -> ptrBox -> x1,
		      ptr -> ptrCmdType -> ptrBox -> y1,
		      ptr -> ptrCmdType -> ptrBox -> x2,
		      ptr -> ptrCmdType -> ptrBox -> y2 );
	 else if( !strcmp( ptr -> ptrCmdName, "CIRCLE" ) )
	    draw_circle( ptr -> ptrCmdType -> ptrCircle -> x,
			 ptr -> ptrCmdType -> ptrCircle -> y,
			 ptr -> ptrCmdType -> ptrCircle -> radius );
	 else if( !strcmp( ptr -> ptrCmdName, "ELLIPSE" ) )
	    draw_ellipse( ptr -> ptrCmdType -> ptrEllipse -> x,
			  ptr -> ptrCmdType -> ptrEllipse -> y,
			  ptr -> ptrCmdType -> ptrEllipse -> xradius,
			  ptr -> ptrCmdType -> ptrEllipse -> yradius );

	 ptr = ptr -> ptrNext;
      }

      mouse_ShowCursor();                           // Rep”e o cursor do mouse

      while( mouse_ButtonStatus() == MB_RIGHT );
      while( mouse_ButtonStatus() != MB_RIGHT );
      while( mouse_ButtonStatus() == MB_RIGHT );

      mouse_HideCursor();               // Esconde o cursor do cursor do mouse

      setwritemode( XOR_PUT );          // Rep”e o modo de escrita do programa
   }

   display_toolbox();                              // Rep”e a Toolbox no ecran
   mouse_ShowCursor();                              // Rep”e o cursor do mouse
   setcolor( nForeColor );	                       // Rep”e a cor anterior
   setbkcolor( nBackColor );                  // Rep”e a cor de fundo anterior
}
