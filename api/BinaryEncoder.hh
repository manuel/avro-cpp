/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef avro_BinaryEncoder_hh__
#define avro_BinaryEncoder_hh__

#include "Encoder.hh"
#include "Stream.hh"

namespace avro {

class BinaryEncoder : public Encoder {
    StreamWriter out_;
    uint8_t *next_;
    uint8_t *end_;

    void init(OutputStream& os);
    StreamWriter &getStreamWriter();
    void flush();
    void encodeNull();
    void encodeBool(bool b);
    void encodeInt(int32_t i);
    void encodeLong(int64_t l);
    void encodeFloat(float f);
    void encodeDouble(double d);
    void encodeString(const std::string& s);
    void encodeBytes(const uint8_t *bytes, size_t len);
    void encodeFixed(const uint8_t *bytes, size_t len);
    void encodeEnum(size_t e);
    void arrayStart();
    void arrayEnd();
    void mapStart();
    void mapEnd();
    void setItemCount(size_t count);
    void startItem();
    void encodeUnionIndex(size_t e);

    void doEncodeLong(int64_t l);
};

} // namespace avro

#endif
