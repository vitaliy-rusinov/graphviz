#include "windows.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>
struct Vertex;
typedef struct refList{
	refList* next;
	refList* prev;
	Vertex* Refto;
} refList;
struct point {
	float x;
	float y;
};

typedef struct Vertex{
	Vertex* next;
	Vertex* prev;
	refList* list;
	refList* lastList;
	point* tag;
} Vertex;


class Graph
{
protected:
	Vertex* myvert;
	Vertex* last;
	int vertc;
public:
	Vertex* getlast(){ return last;}
	void addVertexlist(Vertex* vt){
		Vertex* tempV=new Vertex;
		Vertex* tmp2=vt;
		while(tmp2){
		memcpy(tempV, tmp2,sizeof(Vertex));
		if(!last){last=tempV; myvert=tempV;vertc=1;}
		else{
		last->next=tempV;
		tempV->prev=last;
		last=tempV;		vertc++;}
		tmp2=tmp2->next;

		}
	}
	void addrefList(Vertex* a, refList* rl)
	{
		refList* tempR=new refList;
		refList* tmp2=rl;
		while(tmp2){
		memcpy(tempR, tmp2,sizeof(refList));
		if(!a->lastList){
		a->list=a->lastList=tempR;
		}
		else
		{
		a->lastList->next=tempR;
		tempR->prev=a->lastList;
		a->lastList=tempR;
		}
		tmp2=tmp2->next;
		}
	}
	Graph(){
		myvert=new Vertex;
		last=NULL;
		vertc=0;
		ZeroMemory(myvert,sizeof(Vertex));
	}
	void draw(){
		
		FILE* out=fopen("graph.txt","w");
		fprintf(out,"%d\n",this->vertc);
		Vertex* tvert=this->myvert;
		for(int cc1=0;cc1<this->vertc;cc1++){
			float r=this->vertc *100/3;
			float x=cos((float)(cc1+1)/vertc*2*M_PI)*r;
			float y=sin((float)(cc1+1)/vertc*2*M_PI)*r;
			tvert->tag=new point;tvert->tag->x=x;tvert->tag->y=y;
			tvert=tvert->next;
			fprintf(out,"%f\r\n%f\r\n",x,y);
		}
		Vertex* v;
		v=this->myvert;
		while(v){
		  refList* rL;
		  rL=v->list;
		  while(rL)
		  {
			  if(rL->Refto){
				  fprintf(out,"%f\r\n%f\r\n%f\r\n%f\r\n",v->tag->x,v->tag->y,rL->Refto->tag->x,rL->Refto->tag->y);
			  }
			  rL=rL->next;
		  }
			v=v->next;
		}
		fprintf(out,"END");
		fclose(out);
	}
	
}; 