#ffmpeg��Ƶ�������

##Ŀ¼��
###SDL_AudioSpec
###AVSampleFormat
###


##�ṹ����
###SDL_AudioSpec 
```
typedef struct SDL_AudioSpec
{
    int freq;                   //ÿ��������� 		/**< DSP frequency -- samples per second */
    SDL_AudioFormat format;     //��Ƶ���ݵĸ�ʽ	/**< Audio data format */
    Uint8 channels;             //ͨ������1-��������2-����	/**< Number of channels: 1 mono, 2 stereo */
    Uint8 silence;              //Ĭ��ֵ������������/**< Audio buffer silence value (calculated) */
    Uint16 samples;             //������������С	/**< Audio buffer size in samples (power of 2) */
    Uint16 padding;             //һЩ��Ҫ�ı��뻷����	/**< Necessary for some compile environments */
    Uint32 size;                //��Ƶ�������ֽ���	/**< Audio buffer size in bytes (calculated) */
    SDL_AudioCallback callback; //�ص�����
    void *userdata;				//�û�����
} SDL_AudioSpec;

```
* SDL_AudioFormat �� Uint16�ı�����
* SDL_AudioCallback ��һ������ָ�롣
* Uint8 �� uint8_t �ı�����
* Sint8 �� int8_t �ı�����

###
```AVSampleFormat
enum AVSampleFormat {
    AV_SAMPLE_FMT_NONE = -1,
    AV_SAMPLE_FMT_U8,          ///< unsigned 8 bits
    AV_SAMPLE_FMT_S16,         ///< signed 16 bits
    AV_SAMPLE_FMT_S32,         ///< signed 32 bits
    AV_SAMPLE_FMT_FLT,         ///< float
    AV_SAMPLE_FMT_DBL,         ///< double

    AV_SAMPLE_FMT_U8P,         ///< unsigned 8 bits, planar
    AV_SAMPLE_FMT_S16P,        ///< signed 16 bits, planar
    AV_SAMPLE_FMT_S32P,        ///< signed 32 bits, planar
    AV_SAMPLE_FMT_FLTP,        ///< float, planar
    AV_SAMPLE_FMT_DBLP,        ///< double, planar

    AV_SAMPLE_FMT_NB           ///< Number of sample formats. DO NOT USE if linking dynamically
};
```