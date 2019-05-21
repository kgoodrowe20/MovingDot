
#include <MeggyJrSimple.h>

int x,y,enemyx,enemyy;

void setup() 
{
  MeggyJrSimpleSetup();
  x = 2;
  y = 2;
  enemyx = random(8);
  enemyy= random(8);
}

void loop() 
{
  obstacles();
  DrawPx (x, y, Green);
  DrawPx(enemyx, enemyy, 1);
  movement();
  check();
  MoveEnemy();
  DisplaySlate();
  ClearSlate();
}

void obstacles()
{
  DrawPx (4, 3, 1);
  DrawPx (5, 2, 1);
  DrawPx (6, 1, 1);

  DrawPx (1, 6, 1);
  DrawPx (2, 5, 1);
  DrawPx (3, 4, 1);
  DrawPx (3, 3, 1);
  
}

void movement()
{
  CheckButtonsPress();
  if(Button_Left)
   {
   if(ReadPx(x-1,y) != 1)
   {
    x--;
   }
  }
  if(Button_Right)
  {
   if(ReadPx(x+1,y) != 1)
   {
    x++;
   }
  }
  if(Button_Up)
   {
   if(ReadPx(x,y+1) != 1)
    {
     y++;
    }
   }
  if(Button_Down)
  {
   if(ReadPx(x,y-1) != 1)
   {
    y--;
   }
  }
}

void check()
{
  if(x > 7)
  {
    x = 7;
  }
  if(x < 0)
  {
    x = 0;
  }
  if(y > 7)
  {
    y = 7;
  }
  if(y < 0)
  {
    y = 0;
  }
}

void MoveEnemy()
{
  delay(100);
  if(x>enemyx)
    {
      enemyx++;
    }
  if(y>enemyy)
    {
      enemyy++;
    }
     if(x<enemyx)
    {
      enemyx--;
    }
  if(y<enemyy)
    {
      enemyy--;
    }
   
}
