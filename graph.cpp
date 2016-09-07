#include "graph.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <strstream>

int main(int argc, char** argv)
{
	
	Graph* gr=new Graph();
	
	{
	 using namespace std;
	 cout<<"Vvedite matrizu smezhnosti\n";
	 string temps;	 getline(cin,temps);
	 int tint=0;
	 
	 strstream* st1=new strstream((char*)temps.c_str(),(std::streamsize) 1000);
	 if(temps.length()){
		 int numvert=1;
		Vertex* tv1=new Vertex; ZeroMemory(tv1,sizeof(Vertex));
		gr->addVertexlist(tv1);
		Vertex* firstvert=tv1=gr->getlast();
		refList* trlis=new refList;
		numvert=1;
		*st1>>tint;
	 while(*st1>>tint)
		 {

			 Vertex* tVert=new Vertex;
			 ZeroMemory(tVert,sizeof(Vertex));
			 gr->addVertexlist(tVert);
			 ZeroMemory(trlis,sizeof(refList));
			 trlis->Refto=gr->getlast();
			 gr->addrefList(tv1,trlis);
	 };
	 while(tv1=tv1->next){
		 numvert++;
		 Vertex* tVert=firstvert;
		 getline(cin,temps);
		 tint=0;
		 delete st1; 
		 st1=new strstream((char*)temps.c_str(),(std::streamsize)1000);
		 int cc1=0;
		 while(*st1>>tint)
		 {			
			 if(++cc1==numvert){tVert=tVert->next;continue;}
			 if(tint){
			 ZeroMemory(trlis,sizeof(refList));
			 trlis->Refto=tVert;
			 gr->addrefList(tv1,trlis);
			 }
			 tVert=tVert->next;
		};
	 }
	}
	}
	gr->draw();
	return 0;
	}
