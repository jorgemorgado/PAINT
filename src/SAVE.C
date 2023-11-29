/***
* SAVE.C
* Rotinas para salvar os comandos executados na memória e no disco.
*/

/***
* save_command( void )
* Salva o comando executado para a lista de comandos em memória.
*/
void save_command( void )
{
    if( ptrFirst == NULL )                             // Se a lista está vazia
    {
        ptrFirst = ( LIST * )malloc( sizeof( LIST ) );  // Aloca p/ 1º elemento

        ptrFirst -> ptrPrev = NULL;
        ptrFirst -> ptrNext = NULL;
        ptrFirst -> ptrCmdType = ( CMDTYPE * )malloc( sizeof( CMDTYPE ) );

        switch( nToolboxOp )
        {
            case ICON_POINT:
                ptrFirst -> ptrCmdName = ( char * )malloc( 6 );
                ptrFirst -> ptrCmdName = "POINT";
                ptrFirst -> ptrCmdType -> ptrPoint = ( POINT * )malloc( sizeof( POINT ) );
                ptrFirst -> ptrCmdType -> ptrPoint -> x = *auxCoord[ 0 ];
                ptrFirst -> ptrCmdType -> ptrPoint -> y = *auxCoord[ 1 ];
                break;
            case ICON_LINE:
                ptrFirst -> ptrCmdName = ( char * )malloc( 5 );
                ptrFirst -> ptrCmdName = "LINE";
                ptrFirst -> ptrCmdType -> ptrLine = ( LINE * )malloc( sizeof( LINE ) );
                ptrFirst -> ptrCmdType -> ptrLine -> x1 = *auxCoord[ 0 ];
                ptrFirst -> ptrCmdType -> ptrLine -> y1 = *auxCoord[ 1 ];
                ptrFirst -> ptrCmdType -> ptrLine -> x2 = *auxCoord[ 2 ];
                ptrFirst -> ptrCmdType -> ptrLine -> y2 = *auxCoord[ 3 ];
                break;
            case ICON_BOX:
                ptrFirst -> ptrCmdName = ( char * )malloc( 4 );
                ptrFirst -> ptrCmdName = "BOX";
                ptrFirst -> ptrCmdType -> ptrBox = ( BOX * )malloc( sizeof( BOX ) );
                ptrFirst -> ptrCmdType -> ptrBox -> x1 = *auxCoord[ 0 ];
                ptrFirst -> ptrCmdType -> ptrBox -> y1 = *auxCoord[ 1 ];
                ptrFirst -> ptrCmdType -> ptrBox -> x2 = *auxCoord[ 2 ];
                ptrFirst -> ptrCmdType -> ptrBox -> y2 = *auxCoord[ 3 ];
                break;
            case ICON_CIRCLE:
                ptrFirst -> ptrCmdName = ( char * )malloc( 7 );
                ptrFirst -> ptrCmdName = "CIRCLE";
                ptrFirst -> ptrCmdType -> ptrCircle = ( CIRCLE * )malloc( sizeof( CIRCLE ) );
                ptrFirst -> ptrCmdType -> ptrCircle -> x = *auxCoord[ 0 ];
                ptrFirst -> ptrCmdType -> ptrCircle -> y = *auxCoord[ 1 ];
                ptrFirst -> ptrCmdType -> ptrCircle -> radius = *auxCoord[ 2 ];
                break;
            case ICON_ELLIPSE:
                ptrFirst -> ptrCmdName = ( char * )malloc( 8 );
                ptrFirst -> ptrCmdName = "ELLIPSE";
                ptrFirst -> ptrCmdType -> ptrEllipse = ( ELLIPSE * )malloc( sizeof( ELLIPSE ) );
                ptrFirst -> ptrCmdType -> ptrEllipse -> x = *auxCoord[ 0 ];
                ptrFirst -> ptrCmdType -> ptrEllipse -> y = *auxCoord[ 1 ];
                ptrFirst -> ptrCmdType -> ptrEllipse -> xradius = *auxCoord[ 2 ];
                ptrFirst -> ptrCmdType -> ptrEllipse -> yradius = *auxCoord[ 3 ];
                break;
            default:
                break;
        }

        ptrLast = ptrFirst;
    }
    else                   // Senão, então a lista já tem pelo menos 1 elemento
    {
        LIST *new_element;

        new_element = ( LIST * )malloc( sizeof( LIST ) );// Aloca p/ novo elem.

        ptrLast -> ptrNext = new_element;

        new_element -> ptrPrev = ptrLast;
        new_element -> ptrNext = NULL;
        new_element -> ptrCmdType = ( CMDTYPE * )malloc( sizeof( CMDTYPE ) );

        switch( nToolboxOp )
        {
            case ICON_POINT:
                new_element -> ptrCmdName = ( char * )malloc( 6 );
                new_element -> ptrCmdName = "POINT";
                new_element -> ptrCmdType -> ptrPoint = ( POINT * )malloc( sizeof( POINT ) );
                new_element -> ptrCmdType -> ptrPoint -> x = *auxCoord[ 0 ];
                new_element -> ptrCmdType -> ptrPoint -> y = *auxCoord[ 1 ];
                break;
            case ICON_LINE:
                new_element -> ptrCmdName = ( char * )malloc( 5 );
                new_element -> ptrCmdName = "LINE";
                new_element -> ptrCmdType -> ptrLine = ( LINE * )malloc( sizeof( LINE ) );
                new_element -> ptrCmdType -> ptrLine -> x1 = *auxCoord[ 0 ];
                new_element -> ptrCmdType -> ptrLine -> y1 = *auxCoord[ 1 ];
                new_element -> ptrCmdType -> ptrLine -> x2 = *auxCoord[ 2 ];
                new_element -> ptrCmdType -> ptrLine -> y2 = *auxCoord[ 3 ];
                break;
            case ICON_BOX:
                new_element -> ptrCmdName = ( char * )malloc( 4 );
                new_element -> ptrCmdName = "BOX";
                new_element -> ptrCmdType -> ptrBox = ( BOX * )malloc( sizeof( BOX ) );
                new_element -> ptrCmdType -> ptrBox -> x1 = *auxCoord[ 0 ];
                new_element -> ptrCmdType -> ptrBox -> y1 = *auxCoord[ 1 ];
                new_element -> ptrCmdType -> ptrBox -> x2 = *auxCoord[ 2 ];
                new_element -> ptrCmdType -> ptrBox -> y2 = *auxCoord[ 3 ];
                break;
            case ICON_CIRCLE:
                new_element -> ptrCmdName = ( char * )malloc( 7 );
                new_element -> ptrCmdName = "CIRCLE";
                new_element -> ptrCmdType -> ptrCircle = ( CIRCLE * )malloc( sizeof( CIRCLE ) );
                new_element -> ptrCmdType -> ptrCircle -> x = *auxCoord[ 0 ];
                new_element -> ptrCmdType -> ptrCircle -> y = *auxCoord[ 1 ];
                new_element -> ptrCmdType -> ptrCircle -> radius = *auxCoord[ 2 ];
                break;
            case ICON_ELLIPSE:
                new_element -> ptrCmdName = ( char * )malloc( 8 );
                new_element -> ptrCmdName = "ELLIPSE";
                new_element -> ptrCmdType -> ptrEllipse = ( ELLIPSE * )malloc( sizeof( ELLIPSE ) );
                new_element -> ptrCmdType -> ptrEllipse -> x = *auxCoord[ 0 ];
                new_element -> ptrCmdType -> ptrEllipse -> y = *auxCoord[ 1 ];
                new_element -> ptrCmdType -> ptrEllipse -> xradius = *auxCoord[ 2 ];
                new_element -> ptrCmdType -> ptrEllipse -> yradius = *auxCoord[ 3 ];
                break;
            default:
                break;
        }

        ptrLast = new_element;
    }

    mouseDrag = FALSE;    // Informa que deve terminar o arrastamento da figura
    nrClick = 0;            // Re-inicializa o contador para os clicks no mouse
}


/***
*  save( void )
*  Salva lista de comandos em memória para o ficheiro "JORGE.PNT".
*/
void save( void )
{
    if( ptrFirst != NULL )                         // Se a lista não está vazia
    {
        int n, filehandle;
        char *chrCoord[ MAX_COORDS ];
        LIST *ptr;

        for( n = 0; n < MAX_COORDS; n++ )
        {
            chrCoord[ n ] = ( char * )malloc( 4 * sizeof( char ) );
            *chrCoord[ n ] = NULL;
        }

        filehandle = open( "JORGE.PNT", O_WRONLY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE );

        ptr = ptrFirst;

        while( ptr != NULL )
        {
            write( filehandle, ptr -> ptrCmdName, strlen( ptr -> ptrCmdName ) );
            write( filehandle, " ", strlen( " " ) );

            if( !strcmp( ptr -> ptrCmdName, "POINT" ) )
            {
                itoa( ptr -> ptrCmdType -> ptrPoint -> x, chrCoord[ 0 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrPoint -> y, chrCoord[ 1 ], 10 );
            }
            else if( !strcmp( ptr -> ptrCmdName, "LINE" ) )
            {
                itoa( ptr -> ptrCmdType -> ptrLine -> x1, chrCoord[ 0 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrLine -> y1, chrCoord[ 1 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrLine -> x2, chrCoord[ 2 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrLine -> y2, chrCoord[ 3 ], 10 );
            }
            else if( !strcmp( ptr -> ptrCmdName, "BOX" ) )
            {
                itoa( ptr -> ptrCmdType -> ptrBox -> x1, chrCoord[ 0 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrBox -> y1, chrCoord[ 1 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrBox -> x2, chrCoord[ 2 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrBox -> y2, chrCoord[ 3 ], 10 );
            }
            else if( !strcmp( ptr -> ptrCmdName, "CIRCLE" ) )
            {
                itoa( ptr -> ptrCmdType -> ptrCircle -> x,      chrCoord[ 0 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrCircle -> y,      chrCoord[ 1 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrCircle -> radius, chrCoord[ 2 ], 10 );
            }
            else if( !strcmp( ptr -> ptrCmdName, "ELLIPSE" ) )
            {
                itoa( ptr -> ptrCmdType -> ptrEllipse -> x,       chrCoord[ 0 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrEllipse -> y,       chrCoord[ 1 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrEllipse -> xradius, chrCoord[ 2 ], 10 );
                itoa( ptr -> ptrCmdType -> ptrEllipse -> yradius, chrCoord[ 3 ], 10 );
            }

            write( filehandle, chrCoord[ 0 ], strlen( chrCoord[ 0 ] ) );

            for( n = 1; *chrCoord[ n ] != NULL && n < 4; n++ )
            {
                write( filehandle, ",", strlen( "," ) );
                write( filehandle, chrCoord[ n ], strlen( chrCoord[ n ] ) );
                *chrCoord[ n ] = NULL;
            }

            write( filehandle, ";\n", 2 );

            ptr = ptr -> ptrNext;
        }
    }
}
