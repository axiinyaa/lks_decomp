#include "lib/nw4r/math/math_types.h"
#include <stdint.h>

namespace game {
namespace time {

struct TimeState {
  uint32_t *day;               // 0x00
  float *hour;                 // 0x04
  uint8_t *field_0x08;         // 0x08
  float *field_0x0c;           // 0x0c
  bool timePaused;             // 0x10
  uint8_t padding_0x11[3];     // 0x11–0x13 (undefined bytes)
  float *currentTime;          // 0x14
  uint8_t *currentDate;        // 0x18
  uint8_t padding_0x1c[4];     // 0x1c–0x1f (undefined bytes)
  float *field_0x20;           // 0x20
  uint8_t *field_0x24;         // 0x24
  uint8_t field_0x28;          // 0x28
  uint8_t field_0x29;          // 0x29
  uint8_t padding_0x2a[2];     // 0x2a–0x2b (undefined bytes)
  uint32_t field_0x2c;         // 0x2c
  uint8_t padding_0x30[4];     // 0x30–0x33 (undefined bytes)
  nw4r::math::VEC3 timeVector; // 0x34 (12 bytes: x, y, z floats)

  // Total size: 0x40 (64 bytes)
};

extern TimeState g_TimeState;

TimeState *GetTimeState(void);

} // namespace time
} // namespace game
