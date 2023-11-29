/***
* UNDO.C
* Função que elimina a última tarefa realizada, isto é, apaga a última
* figura desenhada (elimina o último elemento da lista).
*/

/***
* undo( void )
*/
void undo( void )
{
    if( ptrFirst != NULL )
    {
        LIST *ptr = ptrLast;

        mouse_HideCursor();                        // Esconde o cursor do mouse

        if( !strcmp( ptr -> ptrCmdName, "POINT" ) )
        {
            draw_point( ptr -> ptrCmdType -> ptrPoint -> x,
                        ptr -> ptrCmdType -> ptrPoint -> y );
            free( ptr -> ptrCmdType -> ptrPoint );
        }
        else if( !strcmp( ptr -> ptrCmdName, "LINE" ) )
        {
            draw_line( ptr -> ptrCmdType -> ptrLine -> x1,
                       ptr -> ptrCmdType -> ptrLine -> y1,
                       ptr -> ptrCmdType -> ptrLine -> x2,
                       ptr -> ptrCmdType -> ptrLine -> y2 );
            free( ptr -> ptrCmdType -> ptrLine );
        }
        else if( !strcmp( ptr -> ptrCmdName, "BOX" ) )
        {
            draw_box( ptr -> ptrCmdType -> ptrBox -> x1,
                      ptr -> ptrCmdType -> ptrBox -> y1,
                      ptr -> ptrCmdType -> ptrBox -> x2,
                      ptr -> ptrCmdType -> ptrBox -> y2 );
            free( ptr -> ptrCmdType -> ptrBox );
        }
        else if( !strcmp( ptr -> ptrCmdName, "CIRCLE" ) )
        {
            draw_circle( ptr -> ptrCmdType -> ptrCircle -> x,
                         ptr -> ptrCmdType -> ptrCircle -> y,
                         ptr -> ptrCmdType -> ptrCircle -> radius );
            free( ptr -> ptrCmdType -> ptrCircle );
        }
        else if( !strcmp( ptr -> ptrCmdName, "ELLIPSE" ) )
        {
            draw_ellipse( ptr -> ptrCmdType -> ptrEllipse -> x,
                          ptr -> ptrCmdType -> ptrEllipse -> y,
                          ptr -> ptrCmdType -> ptrEllipse -> xradius,
                          ptr -> ptrCmdType -> ptrEllipse -> yradius );
            free( ptr -> ptrCmdType -> ptrEllipse );
        }

        if( ptr -> ptrPrev == NULL )     // Se elemnto a apagar é o 1º da lista
        {
            ptr -> ptrNext -> ptrPrev = NULL;
            ptrFirst = ptrFirst -> ptrNext;
        }
        else                                  // Senão então é o útimo da lista
        {
            ptr -> ptrPrev -> ptrNext = NULL;
            ptrLast = ptrLast -> ptrPrev;
        }

        free( ptr -> ptrCmdName );    // Liberta a memória da string do comando
        free( ptr -> ptrCmdType );      // Liberta a memória do tipo do comando
        free( ptr );          // Liberta a memória alocada pelo último elemento
        mouse_ShowCursor();                          // Repõe o cursor do mouse
    }
}
