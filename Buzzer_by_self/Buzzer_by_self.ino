const int pinBuzzer = 3;
const int beatLength = 400;
/*
   C - do -  261.6HZ；D - re -  293.6HZ；
   E - mi -  329.6HZ；F - fa -  349.2HZ；
   G - sol- 392HZ；A - la -  440HZ；
   B - si -  493.8HZ。
*/
const double C_major[8] = {0, 261.6, 293.6, 329.6, 349.2, 392, 440, 493.8};

int music[2][46] =
{
  { -6, -7, 1, 1, 1, 3, 3, 3, 2, 2, 0, -5, -5, 3, 3, 3, 2, 2, 2, 1, 1, 1, -7, -6, -6, 1, 1, 1, -7, -5, -5, 1, 1, 0, 1, 1, 2, -6, -7, 1, 1, -7, -7, -7, -7, -7},
  {  2, 2, 1, 1, 1, 2, 2, 2, 1, 2, 1, 2, 2, 1, 1, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1}
};
// 奇迹再现高潮部分


/*{
  {1, 1, 5, 5, 6, 6, 5, 4, 4, 3, 3, 2, 2, 1, 5, 5, 4, 4, 3, 3, 2, 5, 5, 4, 4, 3, 3, 2, 1, 1, 5, 5, 6, 6, 5 ,4, 4, 3, 3, 2, 2, 1},
  {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2}
  }
  LittleStars
*/
int musicEnding = 46;
bool enable = true;
void setup()
{
  pinMode(pinBuzzer, OUTPUT);
}

void loop()
{
  if (enable)
  {
    Play();
  }
}

void Play()
{
  int i = 0;
  for (i = 0; i < musicEnding; i++)
  {
    if (music[0][i] > 0)
    {
      tone(pinBuzzer, 2*C_major[music[0][i]]);
      delay(beatLength / music[1][i]);
      noTone(pinBuzzer);
    }
    else if (music[0][i] < 0)
    {
      tone(pinBuzzer, C_major[-music[0][i]]);
      delay(beatLength / music[1][i]);
      noTone(pinBuzzer);
    }
    else
    {
      delay(music[1][i]/beatLength);
    }
  }
  delay(1000);
}
