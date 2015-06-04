Como adicionar arquivos de ajuda
=================================

1. Instale o programa HTML Help Workshop
(Dispon�vel no site: https://www.microsoft.com/en-us/download/details.aspx?id=21138)

2. Crie todas p�ginas de ajuda em formato .htm

3. Abra o arquivo "helpmap.h" e defina um id e um n�mero que ser� relacionado com o arquivo htm.
(Siga o exemplo).

4. Abra o programa instalado na op��o 1. Clique em File, Open e o arquivo "LibraryHelp.hhp".

5. Na aba Project clique em HtmlHelp API Information. � o quarto bot�o que est� ao lado esquerdo da tela.

6. Na aba Alias, clique em "Add...". No primeiro espa�o, escreva o nome da constante ou do n�mero definido no map. D� prefer�ncia � constante, para preservar a est�tica.

7. No segundo espa�o fa�a um link com o arquivo htm criado na op��o 2. D� OK nas duas janelas.

8. Na aba Contents Clique em Insert Heading(2� bot�o � esquerda) para uma nova sec��o e Insert Page(3� bot�o � esquerda) para nova p�gina. Obs.: Caso queira uma nova sec��o ou uma p�gina fora da sec��o atual, clique em OK na mensagem de aviso : "Do you want to insert this entry at the beginning of the table of contents? ", clique em NO caso queira a sec��o/p�gina dentro da sec��o atual.

9. Na aba Index, cria-se chaves que relacionam palavras com uma p�gina.