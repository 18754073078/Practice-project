// ffmpeg_sdl.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>

#include "SDL2/SDL.h"

#define SCREEN_W    640             //���ڵĿ�
#define SCREEN_H    360             //���ڵĸ�
#define PIXEL_W     320             //��Ƶ���صĿ�Ҫ����Ƶ�ļ���ͬ������ʾ����
#define PIXEL_H     180             //���صĸ�
#define BPP         12              //������ȣ�ָ�洢ÿ���������õ�λ����bit��
#define BUF_LEN     ((PIXEL_W) * (PIXEL_H) * (BPP) / 8)     //��һ֡����Ҫ�ռ�

const int bpp = BPP;
int screen_w = SCREEN_W;
int screen_h = SCREEN_H;
const int pixel_w = PIXEL_W;
const int pixel_h = PIXEL_H;

unsigned char buffer[BUF_LEN+1];

int main(int argc, char* argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO)) {
		printf( "Could not initialize SDL - %s\n", SDL_GetError());
		return -1;
	}

	SDL_Window *screen;
	//SDL 2.0 Support for multiple windows
	//��һ�����ڣ���СΪscreen_w * screen_h
	screen = SDL_CreateWindow("Simplest Video Play SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screen_w, screen_h,SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
	if(!screen) {
		printf("SDL: could not create window - exiting:%s\n",SDL_GetError());
		return -1;
	}

	//�½�һ����Ⱦ��
	SDL_Renderer* sdlRenderer = SDL_CreateRenderer(screen, -1, 0);

	Uint32 pixformat=0;
	//IYUV: Y + U + V  (3 planes)
	//YV12: Y + V + U  (3 planes)
	pixformat= SDL_PIXELFORMAT_IYUV;        //???

	SDL_Texture* sdlTexture = SDL_CreateTexture(sdlRenderer,pixformat, SDL_TEXTUREACCESS_STREAMING,pixel_w,pixel_h);

	FILE *fp=NULL;
	fp=fopen("test_yuv420p_320x180.yuv","rb+");

	if(fp==NULL){
		printf("cannot open this file\n");
		return -1;
	}

	SDL_Rect sdlRect;
    int i = 5;
	while(i >= 0){
	        //һ�ζ�1byte���ܹ���һ֡
			if (fread(buffer, 1, pixel_w*pixel_h*bpp/8, fp) != pixel_w*pixel_h*bpp/8){
				// Loop
				fseek(fp, 0, SEEK_SET);
//				fread(buffer, 1, pixel_w*pixel_h*bpp/8, fp);
				i--;
                continue;
			}

            //������������
			SDL_UpdateTexture( sdlTexture, NULL, buffer, pixel_w);

            //(x,y)�Ǵ������ϱ߿�ʼ�ĵ㡣
            //w,h���������ش��ڿ�͸ߣ�ע�ⲻ���������ڣ�
			sdlRect.x = 0;
			sdlRect.y = 0;
			sdlRect.w = screen_w;
			sdlRect.h = screen_h;

			//�����Ⱦ��
			//���������������Ⱦ��
			//��ʾ
			SDL_RenderClear( sdlRenderer );
			SDL_RenderCopy( sdlRenderer, sdlTexture, NULL, &sdlRect);
			SDL_RenderPresent( sdlRenderer );
			//Delay 40ms�� �ӳ�
			SDL_Delay(40);

	}
	SDL_Quit();
	return 0;
}

