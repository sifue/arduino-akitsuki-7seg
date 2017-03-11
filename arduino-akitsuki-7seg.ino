/*
 * ダイナミック接続４桁高輝度青色７セグメントＬＥＤ表示器　アノードコモン　アノード共通接続 [OSL40562-IB]
 * http://akizukidenshi.com/catalog/g/gI-04450/
 * MIT License
 */

int a = 1; // 11
int b = 2; //  7
int c = 3; //  4
int d = 4; //  2
int e = 5; //  1
int f = 6; // 10
int g = 7; //  5
int p = 8; //  3 (DP)

int d4 = 9;  // 6
int d3 = 10; // 8
int d2 = 11; // 9
int d1 = 12; // 12

long del = 5;

void setup()
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);

}

void loop()
{
  long i;
  for (i = 0; i < 1000000; i++)
  {
    showNum(i / 1000);
  }
}

/*
 * 9999 ～ - 999 まで表示
 */
void showNum(int n)
{
  boolean isNega = n < 0;
  
  clearLEDs();
  pickDigit(1);
  if  (n >= 1000) { // 1000以上なら4桁目表示
    pickNumber(n % 10000 / 1000);
  } else if (isNega) { // 負なら反転
    n = -1 * n;
  }
  if (isNega && abs(n) >= 100) dispHyphen();
  delayMicroseconds(del);

  clearLEDs();
  pickDigit(2);
  if (abs(n) >= 100) { // 絶対値100以上なら3桁目表示
    pickNumber(n % 1000 / 100);
  }
  if (isNega && abs(n) < 100 && abs(n) >= 10) dispHyphen();
  delayMicroseconds(del);

  clearLEDs();
  pickDigit(3);
  if (abs(n) >= 10) { // 絶対値10以上なら3桁目表示
    pickNumber(n % 100 / 10);
  }
  if (isNega && abs(n) < 10 && abs(n) >= 1) dispHyphen();
  delayMicroseconds(del);

  clearLEDs();
  pickDigit(4);
  pickNumber(n % 10);
  delayMicroseconds(del);
  n++;
}

void pickDigit(int x)
{
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  switch (x)
  {
    case 1:
      digitalWrite(d1, HIGH);
      break;
    case 2:
      digitalWrite(d2, HIGH);
      break;
    case 3:
      digitalWrite(d3, HIGH);
      break;
    default:
      digitalWrite(d4, HIGH);
      break;
  }
}

void pickNumber(int x)
{
  switch (x)
  {
    default:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
  }
}

void dispDec()
{
  digitalWrite(p, LOW);
}

void dispHyphen()
{
  digitalWrite(g, LOW);
}

void clearLEDs()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(p, HIGH);
}

void zero()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void one()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void two()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void three()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void four()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void five()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void six()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seven()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void eight()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void nine()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}