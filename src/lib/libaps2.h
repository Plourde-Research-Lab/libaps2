/*
 * libaps2.h
 *
 *  Created on: Jun 25, 2012
 *      Author: qlab
 */

#ifndef LIBAPS_H_
#define LIBAPS_H_

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif


#ifdef __cplusplus
extern "C" {
#endif

enum APSErrorCode {
	APS_OK,
	APS_UNKNOWN_ERROR = -1,
	APS_FILE_ERROR = -2
};

EXPORT int get_numDevices();
EXPORT void get_deviceSerials(const char **);

EXPORT int connect_APS(const char *);
EXPORT int disconnect_APS(const char *);

EXPORT int reset(const char *, int);
EXPORT int initAPS(const char *, int);
EXPORT int get_firmware_version(const char *);

EXPORT double get_uptime(const char *);

EXPORT int set_sampleRate(const char *, int);
EXPORT int get_sampleRate(const char *);

EXPORT int set_channel_offset(const char *, int, float);
EXPORT float get_channel_offset(const char *, int);
EXPORT int set_channel_scale(const char *, int, float);
EXPORT float get_channel_scale(const char *, int);
EXPORT int set_channel_enabled(const char *, int, int);
EXPORT int get_channel_enabled(const char *, int);

EXPORT int set_trigger_source(const char *, int);
EXPORT int get_trigger_source(const char *);
EXPORT int set_trigger_interval(const char *, double);
EXPORT double get_trigger_interval(const char *);
EXPORT int trigger(const char *);

EXPORT int set_waveform_float(const char *, int, float*, int);
EXPORT int set_waveform_int(const char *, int, int16_t*, int);
EXPORT int set_markers(const char *, int, uint8_t*, int);

EXPORT int write_sequence(const char *, uint64_t*, uint32_t);

EXPORT int set_run_mode(const char *, int);

EXPORT int load_sequence_file(const char *, const char*);

EXPORT int clear_channel_data(const char *);

EXPORT int run(const char *);
EXPORT int stop(const char *);

EXPORT int get_running(const char *);

EXPORT int set_log(const char *);
EXPORT int set_logging_level(int);

EXPORT const char * get_ip_addr(const char *);
EXPORT int set_ip_addr(const char *, const char *);

/* private API methods */

EXPORT int write_memory(const char *, uint32_t, uint32_t*, uint32_t);
EXPORT int read_memory(const char *, uint32_t, uint32_t*, uint32_t);
EXPORT int read_register(const char *, uint32_t);
EXPORT int program_FPGA(const char *, const char *);

EXPORT int write_flash(const char *, uint32_t, uint32_t*, uint32_t);
EXPORT int read_flash(const char *, uint32_t, uint32_t, uint32_t*);

EXPORT uint64_t get_mac_addr(const char *);
EXPORT int set_mac_addr(const char *, uint64_t);

EXPORT int write_SPI_setup(const char *);

EXPORT int run_DAC_BIST(const char *, const int, uint16_t*, unsigned int, uint32_t*);
EXPORT int set_DAC_SD(const char *, const int, const uint8_t);

#ifdef __cplusplus
}
#endif

#endif /* LIBAPS_H_ */