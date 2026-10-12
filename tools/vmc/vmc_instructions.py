from dataclasses import dataclass
from enum import Enum
from typing import Any, Self

from PyByteBuffer import ByteBuffer

operation_codes: list[str] = [
    "LABEL",
    "LOAD",
    "ADDR",
    "PUSH",
    "POP",
    "ASS",
    "ADD",
    "SUB",
    "MUL",
    "DIV",
    "MOD",
    "INV",
    "COMP",
    "JMP",
    "CJMP",
    "CALL",
    "RET",
    "PRNT",
    "EXT",
    "HALT",
    "SPND",
]


class Code(Enum):
    INT = 0
    FLOAT = 1
    STRING = 2
    POINTER = 3


class VMInstruction:
    op_code: int
    size: int

    def __init__(self, op_code: int, size: int) -> None:
        self.op_code = op_code
        self.size = size

    def __eq__(self, other) -> bool:
        return other == self.op_code

    @staticmethod
    def create_instruction(data: ByteBuffer):
        instruction: VMInstruction = VMLabel()

        op_type: int = data.get()

        match op_type:
            case 1:
                instruction = VMLoad(data)
            case 2:
                instruction = VMAddress(data)
            case 3:
                instruction = VMPush(data)

        return instruction

    def __str__(self) -> str:
        return ""

    def get_op_code_str(self) -> str:
        return operation_codes[self.op_code]


class VMLabel(VMInstruction):
    name: str

    def __init__(self) -> None:
        super().__init__(0, 0)

    def __str__(self) -> str:
        return ""


class VMLoad(VMInstruction):
    value: int
    mode: int

    def __init__(self, data: ByteBuffer) -> None:
        super().__init__(1, 3)
        self.value = data.get()
        self.mode = data.get()

    def __str__(self) -> str:
        return f"{self.get_op_code_str()} {self.value}, {self.mode}\n"


class VMAddress(VMInstruction):
    value: int
    mode: int

    def __init__(self, data: ByteBuffer) -> None:
        super().__init__(1, 3)
        self.value = data.get()
        self.mode = data.get()

    def __str__(self) -> str:
        return f"{self.get_op_code_str()} {self.value}, {self.mode}\n"


class VMPush(VMInstruction):
    value: Any
    mode: int

    def __init__(self, data: ByteBuffer) -> None:
        super().__init__(3, 3)
        self.mode = data.get()

        pos: int = data.position

        match self.mode:
            case 0:
                self.value = data.get(pos)
            case 1:
                self.value = data.get(pos)
            case 2:
                self.value = data.get(pos)
            case 3:
                self.value = data.get(pos)

        data.position = data.position + 8

    def __str__(self) -> str:
        return f"{self.get_op_code_str()} {self.value}\n"
