/*
	Write a C program which produces its own source code as its output.
*/

char*s="char*s=%c%s%c;main(){printf(s,34,s,34);}";

main()
{
	printf(s,34,s,34);
}