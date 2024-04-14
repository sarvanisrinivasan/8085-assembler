#include<stdio.h>
int nulling_array(char ch[50])
{
    int i=0;
    while(ch[i]!=0)
    {
        ch[i]=0;
        i++;
    }
}
char assign (char ch[50], int i,int f, char a, char b, char c, char d, char e, char h, char l, char m)
{
       if(f!=1)
       {
         i++;
         i=space_checking(i,ch);
       }
       if((ch[i]==65)||(ch[i]==48))
        {
            return a;
        }
        else if((ch[i]==66)||(ch[i]==49))
        {
            return b;
        }
        else if((ch[i]==67)||(ch[i]==50))
        {
            return c;
        }
        else if((ch[i]==68)||(ch[i]==51))
        {
            return d;
        }
        else if((ch[i]==69)||(ch[i]==52))
        {
            return e;
        }
        else if((ch[i]==72)||(ch[i]==53))
        {
            return h;
        }
        else if((ch[i]==76)||(ch[i]==54))
        {
            return l;
        }
        else if((ch[i]==77)||(ch[i]==55))
        {
            return m;
        }
        else
        {
            return 0;
        }
}
int breaking(int b,char ch[50])
{
    int g=0;
    if(ch[b]!=10)
    {
       g=1;
    }
    return g;
}
int nextreg(char ch[50], int i,int b,int f)
{
    if((ch[i]==44)||(f==1))
    {
        int s=breaking(b,ch);
        return s;
    }
}
char mov_instruction(char ch[50],int i,int f,char a, char b, char c, char d, char e, char h, char l, char m)
{
    char p=0;
    i++;
    i=space_checking(i,ch);
    int o;
    if(f!=1)
    {
      o=i+2;
    }
    else
    {
        o=i+1;
    }
    int k=nextreg(ch,i,o,f);
    if(k!=1)
    {
       p=assign(ch,i,f,a,b,c,d,e,h,l,m);
    }
    return p;
}
int space_checking(int i, char ch[50])
{
    if(ch[i]==32)
    {
        i++;
    }
    return i;
}
int pow(int a, int k)
{
    int p=1;
    while(k!=0)
    {
        p*=a;
        k--;
    }
    return p;
}
int bytesegregate(char ch[50],int i,int h)
{
    int g=0;
    int k=1;
    while((h!=1)&&(k>=0))
    {
        if((ch[i]>=48)&&(ch[i]<=57))
        {
             int q=pow(16,k);
             g+=(ch[i]-48)*(q);
             k--;
             i++;
        }
        else if((ch[i]>=65)&&(ch[i]<=70))
        {
            int q=pow(16,k);
            g+=(ch[i]-55)*(q);
            k--;
            i++;
        }
        else
        {
            g+=0;
            k--;
            i++;
        }
    }
    return g;
}
int instruction_directaddressing(int i,char ch [50], char c[3],int j)
{
   int u=0;
   int h=0;
   c[0]=j;
   i++;
   i=space_checking(i,ch);
   u=i+4;
   h=breaking(u,ch);
   c[1]=bytesegregate(ch,i,h);
   i=i+2;
   c[2]=bytesegregate(ch,i,h);
}
int withoutreg(int i, char ch[50], int a)
{
    i++;
    int h=breaking(i,ch);
    int d=0;
    if(h!=1)
    {
        d=a;
    }
    return d;
}
char fourreg(int i,char ch[50],int f,char a, char b, char c, char d)
{
    int h=0;
    int j=0;
    i++;
    i=space_checking(i,ch);
    int u=i+1;
    h=breaking(u,ch);
    if((h!=1)||(f==1))
    {
        j=1;
        if(ch[i]==66)
        {
            return a;
        }
        else if(ch[i]==68)
        {
            return b;
        }
        else if(ch[i]==72)
        {
            return c;
        }
    }
    u=i+3;
    h=breaking(u,ch);
    if(((h!=1)&&(j!=1))||(f==1))
    {
            if((ch[i]==80)||(ch[i]==83))
            {
                i++;
                if(ch[i]==83)
                {
                    i++;
                    if(ch[i]==87)
                    {
                        return d;
                    }
                }
                else if(ch[i]==80)
                {
                    return d;
                }
            }
    }
}
int twobyte(char ch[50],int i,int h,char b[2], int a)
{
    b[0]=a;
    i++;
    if(h!=1)
    {
      i=space_checking(i,ch);
      i=i+1;
    }
    int u=i+3;
    if((ch[i]!=32)&&(ch[i]!=44))
    {
        u=i+2;
    }
    int d=nextreg(ch,i,u,h);
    if(h!=1)
    {
      i++;
    }
    else
    {
        i=space_checking(i,ch);
    }
    b[1]=bytesegregate(ch,i,d);
}
int main()
{
    FILE*filename;
    filename=fopen("8085.asc","r");
    FILE *fp;
    fp=fopen("8085.bin","wb");
    while(!feof(filename))
    {
        char ch[50]={};
        nulling_array(ch);
        fgets(ch,50,filename);
        char a=0;
        char b[2]={};
        char c[3]={};
        int i=0;
        if(ch[i]==77)
        {
            i++;
            if(ch[i]==79)
            {
                i++;
                if(ch[i]==86)
                {
                    i++;
                    i=space_checking(i,ch);
                    if(ch[i]==65)
                    {
                       a=mov_instruction(ch,i,0,127,120,121,122,123,124,125,126);
                       fwrite(&a,sizeof(a),1,fp);
                    }
                    else if(ch[i]==66)
                    {
                        a=mov_instruction(ch,i,0,71,64,65,66,67,68,69,70);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                    else if(ch[i]==67)
                    {
                        a=mov_instruction(ch,i,0,79,72,73,74,75,76,77,78);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                    else if(ch[i]==68)
                    {
                        a=mov_instruction(ch,i,0,87,80,81,82,83,84,85,86);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                    else if(ch[i]==69)
                    {
                        a=mov_instruction(ch,i,0,95,88,89,90,91,92,93,94);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                    else if(ch[i]==72)
                    {
                        a=mov_instruction(ch,i,0,103,96,97,98,99,100,101,102);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                    else if(ch[i]==76)
                    {
                        a=mov_instruction(ch,i,0,111,104,105,106,107,108,109,110);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                    else if(ch[i]==77)
                    {
                        a=mov_instruction(ch,i,0,119,112,113,114,115,116,117,118);
                        fwrite(&a,sizeof(a),1,fp);
                    }

                }
            }
            else if(ch[i]==86)
            {
                i++;
                if(ch[i]==73)
                {
                    a=assign(ch,i,0,62,6,14,22,30,38,46,54);
                    twobyte(ch,i,0,b,a);
                    fwrite(&b,sizeof(b),1,fp);
                }
            }
        }
        else if(ch[i]==67)
        {
            i++;
            if(ch[i]==77)
            {
                i++;
                if(ch[i]==65)
                {
                    a=withoutreg(i,ch,47);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==67)
                {
                   a=withoutreg(i,ch,63);
                   fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==80)
                {
                   a=mov_instruction(ch,i,1,191,184,185,186,187,188,189,190);
                   fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==32)
                {
                    instruction_directaddressing(i,ch,c,252);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if((ch[i]>=48)&&(ch[i]<=57)||(ch[i]>=65)&&(ch[i]<=70))
                {
                    i--;
                    instruction_directaddressing(i,ch,c,252);
                    fwrite(c,sizeof(c),1,fp);
                }
            }
            else if(ch[i]==80)
            {
                i++;
                if(ch[i]==73)
                {
                  a=withoutreg(i,ch,254);
                  fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==79)
                {
                    instruction_directaddressing(i,ch,c,228);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(ch[i]==69)
                {
                    instruction_directaddressing(i,ch,c,236);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(ch[i]==32)
                {
                    instruction_directaddressing(i,ch,c,244);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if((ch[i]>=48)&&(ch[i]<=57)||(ch[i]>=65)&&(ch[i]<=70))
                {
                    i--;
                    instruction_directaddressing(i,ch,c,244);
                    fwrite(c,sizeof(c),1,fp);
                }
            }
            else if(ch[i]==78)
            {
                i++;
                if(ch[i]==90)
                {
                    instruction_directaddressing(i,ch,c,196);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(ch[i]==67)
                {
                    instruction_directaddressing(i,ch,c,212);
                    fwrite(c,sizeof(c),1,fp);
                }
            }
            else if(ch[i]==90)
            {
                instruction_directaddressing(i,ch,c,204);
                fwrite(c,sizeof(c),1,fp);
            }
            else if(ch[i]==67)
            {
                instruction_directaddressing(i,ch,c,220);
                fwrite(c,sizeof(c),1,fp);
            }
            else if(ch[i]==65)
            {
                i++;
                if(ch[i]==76)
                {
                    i++;
                    if(ch[i]==76)
                    {
                        instruction_directaddressing(i,ch,c,205);
                        fwrite(c,sizeof(c),1,fp);
                    }
                }
            }
        }
        else if(ch[i]==74)
        {
            i++;
            if(ch[i]==77)
            {
                i++;
                if(ch[i]==80)
                {
                    instruction_directaddressing(i,ch,c,195);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(ch[i]==32)
                {
                    instruction_directaddressing(i,ch,c,250);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(((ch[i]>=48)&&(ch[i]<=57))||((ch[i]>=65)&&(ch[i]<=70)))
                {
                    i--;
                    instruction_directaddressing(i,ch,c,250);
                    fwrite(c,sizeof(c),1,fp);
                }
            }
            else if(ch[i]==78)
            {
                i++;
                if(ch[i]==90)
                {
                    instruction_directaddressing(i,ch,c,194);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(ch[i]==67)
                {
                    instruction_directaddressing(i,ch,c,210);
                    fwrite(c,sizeof(c),1,fp);
                }
            }
            else if(ch[i]==80)
            {
                i++;
                if(ch[i]==79)
                {
                    instruction_directaddressing(i,ch,c,226);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(ch[i]==69)
                {
                    instruction_directaddressing(i,ch,c,234);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(ch[i]==32)
                {
                    instruction_directaddressing(i,ch,c,242);
                    fwrite(c,sizeof(c),1,fp);
                }
                else if(((ch[i]>=48)&&(ch[i]<=57))||((ch[i]>=65)&&(ch[i]<=70)))
                {
                    i--;
                    instruction_directaddressing(i,ch,c,242);
                    fwrite(c,sizeof(c),1,fp);
                }
            }
            else if(ch[i]==90)
            {
                instruction_directaddressing(i,ch,c,202);
                fwrite(c,sizeof(c),1,fp);
            }
            else if(ch[i]==67)
            {
                instruction_directaddressing(i,ch,c,218);
                fwrite(c,sizeof(c),1,fp);
            }
        }
        else if(ch[i]==82)
        {
            i++;
            if(ch[i]==76)
            {
                i++;
                if(ch[i]==67)
                {
                    a=withoutreg(i,ch,7);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==65)
            {
                i++;
                if(ch[i]==76)
                {
                    a=withoutreg(i,ch,23);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==82)
                {
                    a=withoutreg(i,ch,31);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==78)
            {
                i++;
                if(ch[i]==67)
                {
                    a=withoutreg(i,ch,208);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==90)
                {
                    a=withoutreg(i,ch,192);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==80)
            {
                i++;
                if(ch[i]==79)
                {
                    a=withoutreg(i,ch,224);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==69)
                {
                    a=withoutreg(i,ch,232);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==10)
                {
                    a=240;
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==82)
            {
                i++;
                if(ch[i]==67)
                {
                    a=withoutreg(i,ch,15);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==69)
            {
                i++;
                if(ch[i]==84)
                {
                    a=withoutreg(i,ch,201);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==90)
            {
                a=withoutreg(i,ch,200);
                fwrite(&a,sizeof(a),1,fp);
            }
            else if(ch[i]==67)
            {
                a=withoutreg(i,ch,216);
                fwrite(&a,sizeof(a),1,fp);
            }
            else if(ch[i]==77)
            {
                a=withoutreg(i,ch,248);
                fwrite(&a,sizeof(a),1,fp);
            }
            else if(ch[i]==83)
            {
                i++;
                if(ch[i]==84)
                {
                   a=mov_instruction(ch,i,1,199,207,215,223,231,239,247,255);
                   fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==73)
            {
                i++;
                if(ch[i]==77)
                {
                    a=withoutreg(i,ch,32);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
        }
        else if(ch[i]==80)
        {
            i++;
            if(ch[i]==67)
            {
                i++;
                if(ch[i]==72)
                {
                    i++;
                    if(ch[i]==76)
                    {
                      a=withoutreg(i,ch,233);
                      fwrite(&a,sizeof(a),1,fp);
                    }
                }
            }
            else if(ch[i]==85)
            {
                i++;
                if(ch[i]==83)
                {
                    i++;
                    if(ch[i]==72)
                    {
                       a=fourreg(i,ch,0,197,213,229,245);
                       fwrite(&a,sizeof(a),1,fp);
                    }
                }
            }
            else if(ch[i]==79)
            {
                i++;
                if(ch[i]==80)
                {
                    a=fourreg(i,ch,0,193,209,225,241);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
        }
        else if(ch[i]==69)
        {
            i++;
            if(ch[i]==73)
            {
                a=withoutreg(i,ch,251);
                fwrite(&a,sizeof(a),1,fp);
            }
        }
        else if(ch[i]==78)
        {
            i++;
            if(ch[i]==79)
            {
                i++;
                if(ch[i]==80)
                {
                    a=withoutreg(i,ch,0);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
        }
        else if(ch[i]==72)
        {
            i++;
            if(ch[i]==76)
            {
                i++;
                if(ch[i]==84)
                {
                    a=withoutreg(i,ch,118);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
        }
        else if(ch[i]==88)
        {
            i++;
            if(ch[i]==67)
            {
                i++;
                if(ch[i]==72)
                {
                    i++;
                    if(ch[i]==71)
                    {
                        a=withoutreg(i,ch,235);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                }
            }
            else if(ch[i]==84)
            {
                i++;
                if(ch[i]==72)
                {
                    i++;
                    if(ch[i]==76)
                    {
                        a=withoutreg(i,ch,227);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                }
            }
            else if(ch[i]==82)
            {
                i++;
                if(ch[i]==65)
                {
                    a=mov_instruction(ch,i,1,175,168,169,170,171,172,173,174);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==73)
                {
                    twobyte(ch,i,1,b,238);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
        }
        else if(ch[i]==76)
        {
            i++;
            if(ch[i]==88)
            {
                i++;
                if(ch[i]==73)
                {
                   a=fourreg(i,ch,1,1,17,33,49);
                   i++;
                   i=space_checking(i,ch);
                   i=i+1+1*!(a-49);
                   instruction_directaddressing(i,ch,c,a);
                   fwrite(c,sizeof(c),1,fp);
                }
            }
            else if(ch[i]==68)
            {
                i++;
                if(ch[i]==65)
                {
                    i++;
                    if(ch[i]==88)
                    {
                        a=fourreg(i,ch,0,10,26,0,0);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                    else
                    {
                        i=i-(1*!(!(ch[i]-32)));
                        instruction_directaddressing(i,ch,c,58);
                        fwrite(c,sizeof(c),1,fp);
                    }
                }
            }
            else if(ch[i]==72)
            {
                i++;
                if(ch[i]==76)
                {
                    i++;
                    if(ch[i]==68)
                    {
                        instruction_directaddressing(i,ch,c,42);
                        fwrite(c,sizeof(c),1,fp);
                    }
                }
            }
        }
        else if(ch[i]==83)
        {
            i++;
            if(ch[i]==84)
            {
                i++;
                if(ch[i]==65)
                {
                    i++;
                    if(ch[i]==88)
                    {
                        a=fourreg(i,ch,0,2,18,0,0);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                    else
                    {
                        i=i-(1*!(!(ch[i]-32)));
                        instruction_directaddressing(i,ch,c,50);
                        fwrite(c,sizeof(c),1,fp);
                    }
                }
                else if(ch[i]==67)
                {
                    a=withoutreg(i,ch,55);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==72)
            {
                i++;
                if(ch[i]==76)
                {
                    i++;
                    if(ch[i]==68)
                    {
                        instruction_directaddressing(i,ch,c,34);
                        fwrite(c,sizeof(c),1,fp);
                    }
                }
            }
            else if(ch[i]==85)
            {
                i++;
                if(ch[i]==66)
                {
                    a=mov_instruction(ch,i,1,151,144,145,146,147,148,149,150);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==73)
                {
                    twobyte(ch,i,1,b,214);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
            else if(ch[i]==66)
            {
                i++;
                if(ch[i]==66)
                {
                    a=mov_instruction(ch,i,1,159,152,153,154,155,156,157,158);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==73)
                {
                    twobyte(ch,i,1,b,222);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
            else if(ch[i]==80)
            {
                i++;
                if(ch[i]==72)
                {
                    i++;
                    if(ch[i]==76)
                    {
                        a=withoutreg(i,ch,249);
                        fwrite(&a,sizeof(a),1,fp);
                    }
                }
            }
            else if(ch[i]==73)
            {
                i++;
                if(ch[i]==77)
                {
                    a=withoutreg(i,ch,48);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
        }
        else if(ch[i]==65)
        {
            i++;
            if(ch[i]==68)
            {
                i++;
                if(ch[i]==68)
                {
                    a=mov_instruction(ch,i,1,135,128,129,130,131,132,133,134);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==67)
                {
                    a=mov_instruction(ch,i,1,143,136,137,138,139,140,141,142);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==73)
                {
                    twobyte(ch,i,1,b,198);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
            else if(ch[i]==67)
            {
                i++;
                if(ch[i]==73)
                {
                    twobyte(ch,i,1,b,206);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
            else if(ch[i]==78)
            {
                i++;
                if(ch[i]==65)
                {
                    a=mov_instruction(ch,i,1,167,160,161,162,163,164,165,166);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==73)
                {
                    twobyte(ch,i,1,b,230);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
        }
        else if(ch[i]==68)
        {
            i++;
            if(ch[i]==65)
            {
                i++;
                if(ch[i]==68)
                {
                   a=fourreg(i,ch,1,9,25,41,57);
                   fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==65)
                {
                    a=withoutreg(i,ch,39);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==67)
            {
                i++;
                if(ch[i]==82)
                {
                    a=mov_instruction(ch,i,1,61,05,13,21,29,37,45,53);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==88)
                {
                    a=fourreg(i,ch,1,11,27,43,59);
                    fwrite(&a,sizeof(a),1,fp);
                }
            }
            else if(ch[i]==73)
            {
                a=withoutreg(i,ch,243);
                fwrite(&a,sizeof(a),1,fp);
            }
        }
        else if(ch[i]==73)
        {
            i++;
            if(ch[i]==78)
            {
                i++;
                if(ch[i]==82)
                {
                    a=mov_instruction(ch,i,1,60,4,12,20,28,36,44,52);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==88)
                {
                    a=fourreg(i,ch,1,3,19,35,51);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else
                {
                    i--;
                    twobyte(ch,i,1,b,219);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
        }
        else if(ch[i]==79)
        {
            i++;
            if(ch[i]==82)
            {
                i++;
                if(ch[i]==65)
                {
                    a=mov_instruction(ch,i,1,183,176,177,178,179,180,181,182);
                    fwrite(&a,sizeof(a),1,fp);
                }
                else if(ch[i]==73)
                {
                    twobyte(ch,i,1,b,246);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
            else if(ch[i]==85)
            {
                i++;
                if(ch[i]==84)
                {
                    twobyte(ch,i,1,b,211);
                    fwrite(b,sizeof(b),1,fp);
                }
            }
        }
    }
    fclose(fp);
    fclose(filename);
}
