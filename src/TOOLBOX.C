/***
* TOOLBOX.C
* Funções relacionadas com a toolbox.
*/

/***
* option_box( BYTE nColor )
* Exibe uma caixa em volta da opção actualmente seleccionada. Esta opção é
* fornacida pela variável pública nToolboxOp. A função recebe ainda um
* parâmetero que é a cor da caixa a ser exibida.
*/
void option_box( BYTE nColor )
{
    int y;
    int saveColor = getcolor();

    setcolor( nColor );
    mouse_HideCursor();

    outtextxy( ( nToolboxOp * 6 + 1 ) * 8, 53 * 8, "███████" );
    outtextxy( ( nToolboxOp * 6 + 1 ) * 8, 59 * 8, "███████" );

    for( y = 54; y <= 58; y++ )
    {
        outtextxy( ( nToolboxOp * 6 + 1 ) * 8, y * 8, "█" );
        outtextxy( ( ( nToolboxOp + 1 ) * 6 + 1 ) * 8, y * 8, "█" );
    }

    setcolor( saveColor );
    mouse_ShowCursor();
}


/***
* display_toolbox()
* Exibe o menu do programa Paint
*/
void display_toolbox( void )
{
    int x, y;

    for( x = 1; x <= 79; x++ )
    {
        outtextxy( x * 8, 53 * 8, "█" );
        outtextxy( x * 8, 59 * 8, "█" );
    }

    for( x = 1; x <= 79; x += 6 )
        for( y = 54; y <= 58; y++ )
            outtextxy( x * 8, y * 8, "█" );

    outtextxy( 4 * 8, 56 * 8, "." );                            // Icon Point
    line( 8 * 8 + 4, 58 * 8 + 4, 12 * 8 + 3, 54 * 8 + 4 );      // Icon Line

    moveto( 14 * 8 + 4, 54 * 8 + 4 );
    lineto( 18 * 8 + 3, 54 * 8 + 4 );
    lineto( 18 * 8 + 3, 58 * 8 + 3 );                           // Icon Box
    lineto( 14 * 8 + 4, 58 * 8 + 3 );
    lineto( 14 * 8 + 4, 54 * 8 + 4 );

    circle( 22 * 8 + 4, 56 * 8 + 2, 12 );                       // Icon Circle
    ellipse( 28 * 8 + 4, 56 * 8 + 2, 0, 360, 16, 12 );          // Icon Ellipse
    arc( 34 * 8 + 4, 56 * 8 + 2, 160, 0, 14 );                  // Icon Arc

    outtextxy( 38 * 8 + 4, 56 * 8, "FILL" );                    // Icon Fill
    outtextxy( 44 * 8 + 4, 55 * 8 + 2, "COPY" );                // Icon
    outtextxy( 44 * 8 + 4, 56 * 8 + 6, "VIEW" );                //    Copy View
    outtextxy( 50 * 8 + 8, 55 * 8 + 2, "XOR" );                 // Icon
    outtextxy( 50 * 8 + 4, 56 * 8 + 6, "VIEW" );                //    Xor  View
    outtextxy( 56 * 8 + 4, 56 * 8, "UNDO" );                    // Icon Undo
    outtextxy( 62 * 8 + 4, 56 * 8, "LOAD" );                    // Icon Load
    outtextxy( 68 * 8 + 4, 56 * 8, "SAVE" );                    // Icon Save
    outtextxy( 74 * 8 + 4, 56 * 8, "EXIT" );                    // Icon Exit

    settextstyle( DEFAULT_FONT, VERT_DIR, 1 );
    outtextxy( 8, 53 * 8, "Paint94" );
    settextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );

    option_box( RED );
}


/***
* clickIcon( BOOLAEN *iconQuit  )
* Processa a toolbox, isto é, verifica qual o icon que foi seleccionado com
* o rato e em seguida actualiza a variável pública nToolboxOp.
*/
void click_toolbox( BOOLEAN *iconExit )
{
    nrClick = 0;
    mouseDrag = FALSE;

    option_box( WHITE );

    if( yMouse >= 54 * 8 && yMouse < 59 * 8 )
    {
        if(      xMouse >=  2 * 8 && xMouse <  7 * 8 ) // Click no icon Point
            nToolboxOp = ICON_POINT;
        else if( xMouse >=  8 * 8 && xMouse < 13 * 8 ) // Click no icon Line
            nToolboxOp = ICON_LINE;
        else if( xMouse >= 14 * 8 && xMouse < 19 * 8 ) // Click no icon Box
            nToolboxOp = ICON_BOX;
        else if( xMouse >= 20 * 8 && xMouse < 25 * 8 ) // Click no icon Circle
            nToolboxOp = ICON_CIRCLE;
        else if( xMouse >= 26 * 8 && xMouse < 31 * 8 ) // Click no icon Ellipse
            nToolboxOp = ICON_ELLIPSE;
        else if( xMouse >= 32 * 8 && xMouse < 37 * 8 ) // Click no icon Arc
            nToolboxOp = ICON_ARC;
        else if( xMouse >= 38 * 8 && xMouse < 43 * 8 ) // Click no icon Fill
            nToolboxOp = ICON_FILL;
        else if( xMouse >= 44 * 8 && xMouse < 49 * 8 ) //Click no icon CopyView
            nToolboxOp = ICON_COPYVIEW;
        else if( xMouse >= 50 * 8 && xMouse < 55 * 8 ) // Click no icon XorView
            nToolboxOp = ICON_XORVIEW;
        else if( xMouse >= 56 * 8 && xMouse < 61 * 8 ) // Click no icon Undo
            nToolboxOp = ICON_UNDO;
        else if( xMouse >= 62 * 8 && xMouse < 67 * 8 ) // Click no icon Load
            nToolboxOp = ICON_LOAD;
        else if( xMouse >= 68 * 8 && xMouse < 73 * 8 ) // Click no icon Save
            nToolboxOp = ICON_SAVE;
        else if( xMouse >= 74 * 8 && xMouse < 79 * 8 ) // Click no icon Quit
            nToolboxOp = ICON_EXIT;
    }

    option_box( RED );

    switch( nToolboxOp )
    {
        case ICON_FILL:
            break;
        case ICON_COPYVIEW:
            view( COPY_PUT ); break;
        case ICON_XORVIEW:
            view( XOR_PUT );  break;
        case ICON_UNDO:
            undo();      break;
        case ICON_LOAD:
            load();      break;
        case ICON_SAVE:
            save();           break;
        case ICON_EXIT:
            *iconExit = TRUE; break;
        default:
            break;
    }

    while( mouse_ButtonStatus() == MB_RIGHT );
}
