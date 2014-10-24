#ifndef APS2_ERRNO_H_
#define APS2_ERRNO_H_

#include <map>
#include <string>

enum APS2_STATUS {
	APS2_OK,
	APS2_UNKNOWN_ERROR = -1,
	APS2_FILE_ERROR = -2,
	APS2_UNCONNECTED = -3,
	APS2_NO_DEVICE_FOUND = -4,
	APS2_RESET_TIMEOUT =-5,
	APS2_SEQFILE_FAIL = -6
};

static std::map<APS2_STATUS, std::string> messages = {
	{APS2_UNCONNECTED, "Attempt to run library function on unconnected APS2"},
	{APS2_SEQFILE_FAIL, "Failed to load HDF5 sequence file. Check it is present and correctly formatted."},
};




#endif