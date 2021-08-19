%
{
#include <stdio.h>
  int c = 0, oc = 0;
  FILE *fp;
  %
}
% s COMMENT % %
\n { c++; }
"/*"
{
  BEGIN COMMENT;
  printf("\n comment begins in line no : %d\n", c);
  ECHO;
  oc = 1;
}
<COMMENT> "*/"
{
  BEGIN 0;
  ECHO;
  oc = 0;
  printf(": Comment ends in line no %d\n", c);
}
<COMMENT>\n
{
  c++;
  printf("\n");
  ECHO;
}
<COMMENT>. { ECHO; }
.;
% %
    main()
{
  yyin = fopen("5b.txt", "r");
  yylex();
  fclose(yyin);
  if (oc == 1)
  {
    printf("\n comment is not closed till the end of file!");
  }
}