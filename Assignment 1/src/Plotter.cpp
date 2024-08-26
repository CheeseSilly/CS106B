#include "Plotter.h"
#include "strlib.h"
using namespace std;

double *getNum(int index,string line){
    double *pos=new double[2];
    int middle=0;
    string temp[2];
    for(int i=index+1;i<line.length();i++){
        if(line[i]==' '){
            middle=i;
            break;
        }
        temp[0]+=line[i];
    }
    for(int i=middle+1;i<line.length();i++){
        temp[1]+=line[i];
    }
    pos[0]=stringToReal(temp[0]);
    pos[1]=stringToReal(temp[1]);

    return pos;
}

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    double x=0.0,y=0.0;
    // flag=0:penup,falg=1:pendown
    int flag=0;
    string penup="penup";
    string pendown="pendown";
    string moveabs="moveabs";
    string moverel="moverel";
    string penwidth="penwidth";
    string pencolor="pencolor";
    PenStyle style={1,"black"};
    for(string line;getline(input,line);){
       string newline= toLowerCase(line);
        if(newline.find(penup)!=newline.npos){
           flag=0;
        }
        if(newline.find(pendown)!=newline.npos){
            flag=1;
        }
        if(newline.find(moveabs)!=newline.npos){
            int index=newline.find(moveabs)+moveabs.length();
            double abs_x=getNum(index,newline)[0];
            double abs_y=getNum(index,newline)[1];
            if(flag==0){
                x=abs_x;
                y=abs_y;
            }
            else if(flag==1){
                drawLine(x,y,abs_x,abs_y,style);
            }
        }
        if(newline.find(moverel)!=newline.npos){
            int index=newline.find(moverel)+moverel.length();
            double abs_x=getNum(index,newline)[0];
            double abs_y=getNum(index,newline)[1];
            if(flag==0){
                x+=abs_x;
                y+=abs_y;
            }
            else if(flag==1){
                drawLine(x,y,x+abs_x,y+abs_y,style);
            }


        }
        if(newline.find(penwidth)!=newline.npos){
            int index=penwidth.length();
            string temp;
            for(int i=index+1;i<newline.length();i++){
                temp+=newline[i];
            }
            double width=stringToReal(temp);
            style.width=width;

        }
        if(newline.find(pencolor)!=newline.npos){
            int index=pencolor.length();
            string temp;
            for(int i=index+1;i<newline.length();i++){
                temp+=newline[i];
            }
            style.color=temp;

        }
    }
}
