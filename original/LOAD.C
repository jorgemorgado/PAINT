/***
*  LOAD.C
*  Carregar o desenho na mem¢ria a partir do ficheiro em disco.
*/


/***
*  load( void )
*  Carregar o desenho na mem¢ria a partir do ficheiro "JORGE.PNT".
*/
void load( void )
{
   char *ptrFile;
   int filehandle;
   int filelen, fcount = 0;

   while( ptrFirst != NULL )                      // Elimina a lista existente
      undo();

   if( ( filehandle = open( "JORGE.PNT", O_BINARY ) ) == -1 )
      exit( EXIT_FAILURE );      // Aviso que deu erro na abertura do ficheiro

   if( ( filelen = filelength( filehandle ) ) == -1 )
      exit( EXIT_FAILURE );   // Aviso que deu erro na obten‡„o do comprimento

   if( ( ptrFile = ( char * )malloc( filelen ) ) == NULL )
      exit( EXIT_FAILURE );       // Aviso que deu erro na aloca‡„o de mem¢ria

   if( read( filehandle, ptrFile, filelen ) == -1 )
      exit( EXIT_FAILURE );       // Aviso que deu erro na leitura do ficheiro

   if( close( filehandle ) == -1 )
      exit( EXIT_FAILURE );         // Aviso que deu erro no fecho do ficheiro


   while( fcount < filelen )   // Percorre todo o ficheiro obtendo os comandos
   {
      char cmdName[ 20 ];
      int n, nCoordCount = 0;

      for( n = 0; *( ptrFile + fcount ) != ' '; n++, fcount++ )     // Obt‚m o
	 cmdName[ n ] = *( ptrFile + fcount );                      // nome do
								    // comando
      cmdName[ n ] = '\0';                                          // no file

      while( *( ptrFile + fcount ) == ' ' )  // Avan‡a os  espa‡os  existentes
	 fcount++;                           // entre comando e os parƒmeteros

      do
      {
	 char tmpCoord[ 10 ];

	 for( n = 0; *( ptrFile + fcount ) != ',' &&
		     *( ptrFile + fcount ) != ';'; n++, fcount++ )
	    tmpCoord[ n ] = *( ptrFile + fcount );

	 tmpCoord[ n ] = '\0';

	 *auxCoord[ nCoordCount++ ] = atoi( tmpCoord ); // Converte parƒmetero

	 while( *( ptrFile + fcount ) == ' ' || *( ptrFile + fcount ) == ',' )
	    fcount++;                      // Avan‡a at‚ ao pr¢ximo parƒmetero
      }
      while( *( ptrFile + fcount ) != ';' ); // At‚ encontrar fim da instru‡„o


      // Prepara tudo para salvar (colocar na lista) o comando obtido
      if( !strcmp( cmdName, "POINT" ) )
	 nToolboxOp = ICON_POINT;
      else if( !strcmp( cmdName, "LINE" ) )
	 nToolboxOp = ICON_LINE;
      else if( !strcmp( cmdName, "BOX" ) )
	 nToolboxOp = ICON_BOX;
      else if( !strcmp( cmdName, "CIRCLE" ) )
	 nToolboxOp = ICON_CIRCLE;
      else if( !strcmp( cmdName, "ELLIPSE" ) )
	 nToolboxOp = ICON_ELLIPSE;

      // Chama a fun‡„o para salvar o comando obtido dese o ficheiro
      save_command();


      while( fcount < filelen && ( *( ptrFile + fcount ) < 'A' || *( ptrFile + fcount ) > 'Z' ) )
	 fcount++;                            // Avan‡a at‚ ao pr¢ximo comando
   }

   view( XOR_PUT );
   free( ptrFile );
}
