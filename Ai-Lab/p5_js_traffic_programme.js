var s1=-10;
var s2=150;
var y1=1300;
var y2=250;
var z1=1300;
var z2=450;
var q1=0;
var q2=550;
var p=0;
function setup()
{
	createCanvas(screen.width,screen.height);

}
function draw()
{

	background(100,10,200);
	for(var x=0;x<=width;x=x+300)
	{
		for(var y=0;y<=height;y=y+300)
		{
      stroke(0);
			fill(0);
			rect(x,y,150,150);
		}
	}
	fill(255);
	rect(s1,s2+10,30,30);
	fill(255);
	rect(y1-10,y2-10,30,30);
	fill(255);
	rect(q1+40,q2+40,30,30);
	fill(255);
	rect(z1-20,z2,30,30);

	if(s1==150||s1==450||s1==750||s1==1050)
	{
		if(s2==150||s2==450)
		{
			p=int(random(1,4));
		}
	}
	if(p==1)
	{
		s1=s1+5;
		y1=y1-5;
		q1=q1+5;
		z2=z2-5;
	}
	else if(p==2)
	{
		s2=s2+5;
		y2=y2+5;
		q2=q2-5;
		z1=z1-5;
	}
	else if(p==3)
	{
		s1=s1-5;
		y2=y2+5;
		q1=q1-5;
		z2=z2+5;

	}
	else if(p==4)
	{
		s2=s2-5;
		y1=y1-5;
		q2=q2+5;
		z1=z1+5;
	}
	else {
		 s1=s1+5;
		 y1=y1-5;
		 q1=q1+5;
 		z1=z1-5;
	}
	if((s1>=width||s2>=height||s1<=-10||s2<=-10)&&(y1>=width||y2>=height||y1<=-10||y2<=-10)&&(z1>=width||z2>=height||z1<=-10||z2<=-10)&&(q1>=width||q2>=height||q1<=-10||q2<=-10))
	{
		s1=30;
		s2=150;
		p=0;
		y1=1270;
		y2=250;
		z1=1300;
		z2=550;
		q1=20;
		q2=450;
	}


}
