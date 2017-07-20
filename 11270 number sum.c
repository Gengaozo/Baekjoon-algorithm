main()
{
	int a,i,z=0;
	char s[102];
	
	scanf("%d",&a);
	scanf("%s",s);

	for(i=0;i<a;i++)
	{
		z+=s[i]-'0';
	}
	printf("%d",z);
}
