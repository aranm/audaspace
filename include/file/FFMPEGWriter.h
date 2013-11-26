/*******************************************************************************
 * Copyright 2009-2013 Jörg Müller
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

#include "ConverterFunctions.h"
#include "Buffer.h"
#include "IWriter.h"

#include <string>

struct AVCodecContext;
extern "C" {
#include <libavformat/avformat.h>
}

AUD_NAMESPACE_BEGIN

/**
 * This class writes a sound file via ffmpeg.
 */
class FFMPEGWriter : public IWriter
{
private:
	/**
	 * The current position in samples.
	 */
	int m_position;

	/**
	 * The specification of the audio data.
	 */
	DeviceSpecs m_specs;

	/**
	 * The AVFormatContext structure for using ffmpeg.
	 */
	AVFormatContext* m_formatCtx;

	/**
	 * The AVCodecContext structure for using ffmpeg.
	 */
	AVCodecContext* m_codecCtx;

	/**
	 * The AVOutputFormat structure for using ffmpeg.
	 */
	AVOutputFormat* m_outputFmt;

	/**
	 * The AVStream structure for using ffmpeg.
	 */
	AVStream* m_stream;

	/**
	 * The input buffer for the format converted data before encoding.
	 */
	Buffer m_input_buffer;

	/**
	 * The output buffer for the encoded audio data.
	 */
	Buffer m_output_buffer;

	/**
	 * The count of input samples we have so far.
	 */
	unsigned int m_input_samples;

	/**
	 * The count of input samples necessary to encode a packet.
	 */
	unsigned int m_input_size;

	/**
	 * Converter function.
	 */
	convert_f m_convert;

	// hide copy constructor and operator=
	FFMPEGWriter(const FFMPEGWriter&);
	FFMPEGWriter& operator=(const FFMPEGWriter&);

	/**
	 * Encodes to the output buffer.
	 * \param data Pointer to the data to encode.
	 */
	void encode(sample_t* data);

public:
	/**
	 * Creates a new writer.
	 * \param filename The path to the file to be read.
	 * \param specs The file's audio specification.
	 * \param format The file's container format.
	 * \param codec The codec used for encoding the audio data.
	 * \param bitrate The bitrate for encoding.
	 * \exception Exception Thrown if the file specified does not exist or
	 *            cannot be read with ffmpeg.
	 */
	FFMPEGWriter(std::string filename, DeviceSpecs specs, Container format, Codec codec, unsigned int bitrate);

	/**
	 * Destroys the writer and closes the file.
	 */
	virtual ~FFMPEGWriter();

	virtual int getPosition() const;
	virtual DeviceSpecs getSpecs() const;
	virtual void write(unsigned int length, sample_t* buffer);
};

AUD_NAMESPACE_END
