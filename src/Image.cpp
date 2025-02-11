#include "Pixel.h"
#include "Image.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

    
    Image::Image()
    {   
//initialise with 0
        dimx = 0;
        dimy = 0;
    }

    Image::Image(int dimensionX, int dimensionY)
    {   
        if(dimensionX>0 && dimensionY>0)
        {
            dimx = dimensionX;
            dimy = dimensionY;
            tab.resize(dimx * dimy, Pixel());
        }
        else
        {
            dimx =0;
            dimy =0;
            throw out_of_range("Warning: Invalid pixel coordinates!");
        }
        
    }

//for privet parts
    int Image::getdimX() const { return dimx;}
    int Image::getdimY() const { return dimy;}


//for deleting the memory
    Image::~Image()
    {
        dimx =0;
        dimy =0;
        tab.clear();
        cout<<"image jas been deleted";

    }
//for geting the pixel
  Pixel Image::getPix(unsigned int x, unsigned int y)
    {
        if(x>=0 && x<dimx && y>=0 && y<dimy)
        {
            return tab[y*dimx+x];
             
        }
        else 
        {
            throw out_of_range("Warning: Invalid pixel coordinates!");
            
        }
    }


    Pixel Image::getPix(unsigned int x, unsigned int y) const
    {
        if(x>=0 && x<dimx && y>=0 && y<dimy)
        {
            return tab[y*dimx+x];
             
        }
        else 
        {
            throw out_of_range("Warning: Invalid pixel coordinates!");
            
        }
        

    }

    void Image::setPix(unsigned int x, unsigned int y, Pixel couleur)
    {
        if(x<dimx && y<dimy)
        {
            tab[y*dimx+x] = couleur;
        }
        else
        {
            cout<<"warning";
        }
        

    }

    int Image::getTabSize() const
    {
        return tab.size();
    }

    void Image::dessinerRectangle(unsigned int Xmin, unsigned int Xmax , unsigned int Ymin ,  unsigned int Ymax, Pixel couleur)
    {
        if(Xmin<Xmax && Ymin<Ymax)
        {
            for(unsigned int x = Xmin ; x< Xmax; x++ )
            {
                for(unsigned int y = Ymin; y<Ymax; y++)
                {
                    setPix(x,y, couleur);
                }
            }
        }
    }

    void Image::effacer(Pixel couleur)
    {

        dessinerRectangle(0, 0 , dimx-1, dimy-1, couleur);
    }
void Image::testRegression()
{ 
    Image * im1 = new Image();//image that is 0 0
    Image * im2 = new Image(35,35); //image that is 35x35
    //to see if the image im1 and im2 works or not
    cout<< im1->getdimX() << "--" << im1->getdimY() << " and " << im2->getdimX() << " --" << im2->getdimY() <<endl;//ok


    if (im1->getTabSize() == 0)
    {
        cout << "tab de im1 non initialisé." << endl;
    }
    else
    {
        cout << "tab de im1 initialisé." << endl;
    } //ok
    
    //i tried to wite this function in the way blow but it did't work
    Pixel whitePixel(255, 255, 255);
    im2->dessinerRectangle(2, 2, 8, 8, whitePixel);
    //im2->dessinerRectangle(2, 2, 8, 8, {10, 10, 10}); //draw a rectanle

    //get the pixrl and then print each color seperatly with an int
     cout << (int)im2->getPix(4, 6).r << "--"<< (int)im2->getPix(4, 6).g << "--"<< (int)im2->getPix(4, 6).b << endl;
     Pixel moncolor(125,125,125);
     im2->setPix(1, 1, moncolor);
     im2->setPix(41, 41,moncolor);

    cout<<(int)im2->getPix(1, 1).r<<"--"<<(int)im2->getPix(1, 1).g<<"--"<<(int)im2->getPix(1, 1).b<<endl;
    im2->getPix(1, 1);
    Pixel black(0,0,0);
    im2->effacer(black);
    delete im1;
    delete im2;

}

