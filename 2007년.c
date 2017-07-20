#include<stdio.h>

main()
{
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31},j,m,d;
	scanf("%d%d",&m,&d);
	
	for(j=0;j<m-1;j++)		//if month is not 1, add days
	d+=days[j];
	
	switch(d%7)				// 1/1 is monday. multiple of 7 will be day.
	{
		case 0:puts("SUN"); break;
		case 1:puts("MON"); break;
		case 2:puts("TUE"); break;
		case 3:puts("WED"); break;
		case 4:puts("THU"); break;
		case 5:puts("FRI"); break;
		case 6:puts("SAT"); break;
	}
}
