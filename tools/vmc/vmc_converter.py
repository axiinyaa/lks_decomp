from termios import VMIN
from traceback import print_exception

from PyByteBuffer import ByteBuffer

from tools.vmc.vmc_instructions import VMInstruction, VMLabel


class VMCConverter:
    instructions: list[str]
    vmc_path: str = "/home/axii/Documents/Projects/LKSReverseEngineering/lks_decomp/orig/RO3EXJ/files/event/script/main/main.vmc0"
    data: bytes

    size: int
    type: int

    def open_vmc(self, path: str):
        with open(path, "rb") as f:
            raw_data = f.readline()

        if not self.is_vmc(raw_data):
            print("Not a valid VMC file!")

        buffer = ByteBuffer.wrap(raw_data)
        buffer.position = 0xC
        self.size = buffer.get(4)
        self.type = buffer.get(8)

        if self.type != 0:
            buffer.position = 0x10

        print(self.size, self.type)

        code: list[VMInstruction] = []
        last_instruction: VMInstruction = VMLabel()

        while last_instruction != 19:
            last_instruction = VMInstruction.create_instruction(buffer)
            code.append(last_instruction)

            if str(last_instruction) != "":
                print(last_instruction)

        pass

    def is_vmc(self, raw_data: bytes) -> bool:
        return raw_data[0:3] == b"VMC"


VMCConverter().open_vmc(
    "/home/axii/Documents/Projects/LKSReverseEngineering/lks_decomp/orig/RO3EXJ/files/event/script/main/main.vmc0"
)
