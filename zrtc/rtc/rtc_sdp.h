#pragma once

#include <string>
#include <vector>

struct RTPMap {
	int payload_type;
	std::string encoding_name;
	int clock_rate;
};

class RtcSdp
{
public:
	RtcSdp();
	virtual ~RtcSdp();

	bool Parse(std::string sdp);
	std::string Build();

	void SetAddress(std::string ip, uint16_t port);
	void SetIceParams(std::string ice_ufrag, std::string ice_pwd);
	void SetFingerprint(std::string fingerprint);
	void SetStreamName(std::string stream_name);
	void SetVideo(uint32_t ssrc, uint32_t payload_type);
	void SetVideoRtx(uint32_t ssrc, uint32_t payload_type);
	void SetVideoFec(uint32_t ssrc, uint32_t payload_type);
	void SetAudio(uint32_t ssrc, uint32_t payload_type);

	std::string GetIceUfrag();

private:
	std::string ice_ufrag_;
	std::string ice_pwd_;
	std::string fingerprint_;
	std::vector<RTPMap> rtp_maps_;

	std::string stream_name_ = "live";
	uint32_t audio_ssrc_ = 10000;
	uint32_t video_ssrc_ = 20000;
	uint32_t video_rtx_ssrc_ = 0;
	uint32_t video_fec_ssrc_ = 0;
	uint32_t audio_payload_type_ = 111;
	uint32_t video_payload_type_ = 125;
	uint32_t video_fec_payload_type_ = 122;
	uint32_t video_rtx_payload_type_ = 120;
	uint16_t port_ = 10000;
	std::string ip_ = "127.0.0.1";
};

