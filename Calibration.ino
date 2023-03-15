int suma = 0;
int i=0;
int average=0;
int k = 10;
int th = 3300;
int ksum=0;
int sig=0;

int part[10];

int suma1 = 0;
int i1=0;
int average1=0;
int k1 = 10;
int ksum1=0;
int sig1=0;
int th1 = 2150;
int part1[10]; 

void setup() {
 Serial.begin(9600);
}

void loop() {
int EMG0 = analogRead(A0);
int EMG1 = analogRead(A1);
delay(1);

i=i+1;
suma=suma+EMG0;
average=suma/i;
EMG0=abs(EMG0-average);
part[i%k]=EMG0;

if (i%k==0)
{
 ksum=0;
 for (int j=0; j<k; j++)
 {
  ksum=ksum+part[j];
  if (ksum>th)
    sig=1;
  if (ksum<th)
    sig=0;
 }
 Serial.print(ksum);

}

i1=i1+1;
suma1=suma1+EMG1;
average1=suma1/i1;
EMG1=abs(EMG1-average1);
part1[i1%k]=EMG1;

if (i1%k==0)
{
 ksum1=0;
 for (int j1=0; j1<k; j1++)
 {
  ksum1=ksum1+part1[j1];
  if (ksum1>th1)
    sig1=3;
  if (ksum1<th1)
    sig1=2;
 }
 Serial.print(" ");
 Serial.println(ksum1);

}
}
