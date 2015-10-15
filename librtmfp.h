
#ifdef __cplusplus
extern "C" {
#endif

// RTMFP Connection function
// return : index of the connection's context
unsigned int RTMFP_Connect(const char* host, int port, const char* url, void (__cdecl * onSocketError)(const char*), 
						   void (__cdecl * onStatusEvent)(const char*,const char*), void (__cdecl * onMedia)(unsigned int, const char*, unsigned int,int));

// RTMFP NetStream Play function
void RTMFP_Play(unsigned int RTMFPcontext, const char* streamName);

// Close the RTMFP connection
void RTMFP_Close(unsigned int RTMFPcontext);

// Read size bytes of flv data from the current connexion (Asynchronous read, to be called by ffmpeg)
int RTMFP_Read(unsigned int RTMFPcontext, char *buf, unsigned int size);

// Write size bytes of data into the current connexion
int RTMFP_Write(unsigned int RTMFPcontext, const char *buf, int size);

#ifdef __cplusplus
}
#endif
