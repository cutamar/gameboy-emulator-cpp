#include <stdexcept>
#include <iostream>
#include "cpu.h"
#include "mmu.h"

CPU::CPU() : stop{false}, halt{false} {}

void CPU::ExecuteInstruction(uint8_t op_code)
{
    switch (op_code)
    {
    case 0x00:
        NOP();
        break;
    case 0x01:
        LDBCnn();
        break;
    case 0x02:
        LDBCmA();
        break;
    case 0x03:
        INCBC();
        break;
    case 0x04:
        INCr_b();
        break;
    case 0x05:
        DECr_b();
        break;
    case 0x06:
        LDrn_b();
        break;
    case 0x07:
        RLCA();
        break;
    case 0x08:
        LDmmSP();
        break;
    case 0x09:
        ADDHLBC();
        break;
    case 0x0A:
        LDABCm();
        break;
    case 0x0B:
        DECBC();
        break;
    case 0x0C:
        INCr_c();
        break;
    case 0x0D:
        DECr_c();
        break;
    case 0x0E:
        LDrn_c();
        break;
    case 0x0F:
        RRCA();
        break;
    case 0x10:
        DJNZn();
        break;
    case 0x11:
        LDDEnn();
        break;
    case 0x12:
        LDDEmA();
        break;
    case 0x13:
        INCDE();
        break;
    case 0x14:
        INCr_d();
        break;
    case 0x15:
        DECr_d();
        break;
    case 0x16:
        LDrn_d();
        break;
    case 0x17:
        RLA();
        break;
    case 0x18:
        JRn();
        break;
    case 0x19:
        ADDHLDE();
        break;
    case 0x1A:
        LDADEm();
        break;
    case 0x1B:
        DECDE();
        break;
    case 0x1C:
        INCr_e();
        break;
    case 0x1D:
        DECr_e();
        break;
    case 0x1E:
        LDrn_e();
        break;
    case 0x1F:
        RRA();
        break;
    case 0x20:
        JRNZn();
        break;
    case 0x21:
        LDHLnn();
        break;
    case 0x22:
        LDHLIA();
        break;
    case 0x23:
        INCHL();
        break;
    case 0x24:
        INCr_h();
        break;
    case 0x25:
        DECr_h();
        break;
    case 0x26:
        LDrn_h();
        break;
    case 0x27:
        DAA();
        break;
    case 0x28:
        JRZn();
        break;
    case 0x29:
        ADDHLHL();
        break;
    case 0x2A:
        LDAHLI();
        break;
    case 0x2B:
        DECHL();
        break;
    case 0x2C:
        INCr_l();
        break;
    case 0x2D:
        DECr_l();
        break;
    case 0x2E:
        LDrn_l();
        break;
    case 0x2F:
        CPL();
        break;
    case 0x30:
        JRNCn();
        break;
    case 0x31:
        LDSPnn();
        break;
    case 0x32:
        LDHLDA();
        break;
    case 0x33:
        INCSP();
        break;
    case 0x34:
        INCHLm();
        break;
    case 0x35:
        DECHLm();
        break;
    case 0x36:
        LDHLmn();
        break;
    case 0x37:
        SCF();
        break;
    case 0x38:
        JRCn();
        break;
    case 0x39:
        ADDHLSP();
        break;
    case 0x3A:
        LDAHLD();
        break;
    case 0x3B:
        DECSP();
        break;
    case 0x3C:
        INCr_a();
        break;
    case 0x3D:
        DECr_a();
        break;
    case 0x3E:
        LDrn_a();
        break;
    case 0x3F:
        CCF();
        break;
    case 0x40:
        LDrr_bb();
        break;
    case 0x41:
        LDrr_bc();
        break;
    case 0x42:
        LDrr_bd();
        break;
    case 0x43:
        LDrr_be();
        break;
    case 0x44:
        LDrr_bh();
        break;
    case 0x45:
        LDrr_bl();
        break;
    case 0x46:
        LDrHLm_b();
        break;
    case 0x47:
        LDrr_ba();
        break;
    case 0x48:
        LDrr_cb();
        break;
    case 0x49:
        LDrr_cc();
        break;
    case 0x4A:
        LDrr_cd();
        break;
    case 0x4B:
        LDrr_ce();
        break;
    case 0x4C:
        LDrr_ch();
        break;
    case 0x4D:
        LDrr_cl();
        break;
    case 0x4E:
        LDrHLm_c();
        break;
    case 0x4F:
        LDrr_ca();
        break;
    case 0x50:
        LDrr_db();
        break;
    case 0x51:
        LDrr_dc();
        break;
    case 0x52:
        LDrr_dd();
        break;
    case 0x53:
        LDrr_de();
        break;
    case 0x54:
        LDrr_dh();
        break;
    case 0x55:
        LDrr_dl();
        break;
    case 0x56:
        LDrHLm_d();
        break;
    case 0x57:
        LDrr_da();
        break;
    case 0x58:
        LDrr_eb();
        break;
    case 0x59:
        LDrr_ec();
        break;
    case 0x5A:
        LDrr_ed();
        break;
    case 0x5B:
        LDrr_ee();
        break;
    case 0x5C:
        LDrr_eh();
        break;
    case 0x5D:
        LDrr_el();
        break;
    case 0x5E:
        LDrHLm_e();
        break;
    case 0x5F:
        LDrr_ea();
        break;
    case 0x60:
        LDrr_hb();
        break;
    case 0x61:
        LDrr_hc();
        break;
    case 0x62:
        LDrr_hd();
        break;
    case 0x63:
        LDrr_he();
        break;
    case 0x64:
        LDrr_hh();
        break;
    case 0x65:
        LDrr_hl();
        break;
    case 0x66:
        LDrHLm_h();
        break;
    case 0x67:
        LDrr_ha();
        break;
    case 0x68:
        LDrr_lb();
        break;
    case 0x69:
        LDrr_lc();
        break;
    case 0x6A:
        LDrr_ld();
        break;
    case 0x6B:
        LDrr_le();
        break;
    case 0x6C:
        LDrr_lh();
        break;
    case 0x6D:
        LDrr_ll();
        break;
    case 0x6E:
        LDrHLm_l();
        break;
    case 0x6F:
        LDrr_la();
        break;
    case 0x70:
        LDHLmr_b();
        break;
    case 0x71:
        LDHLmr_c();
        break;
    case 0x72:
        LDHLmr_d();
        break;
    case 0x73:
        LDHLmr_e();
        break;
    case 0x74:
        LDHLmr_h();
        break;
    case 0x75:
        LDHLmr_l();
        break;
    case 0x76:
        HALT();
        break;
    case 0x77:
        LDHLmr_a();
        break;
    case 0x78:
        LDrr_ab();
        break;
    case 0x79:
        LDrr_ac();
        break;
    case 0x7A:
        LDrr_ad();
        break;
    case 0x7B:
        LDrr_ae();
        break;
    case 0x7C:
        LDrr_ah();
        break;
    case 0x7D:
        LDrr_al();
        break;
    case 0x7E:
        LDrHLm_a();
        break;
    case 0x7F:
        LDrr_aa();
        break;
    case 0x80:
        ADDr_b();
        break;
    case 0x81:
        ADDr_c();
        break;
    case 0x82:
        ADDr_d();
        break;
    case 0x83:
        ADDr_e();
        break;
    case 0x84:
        ADDr_h();
        break;
    case 0x85:
        ADDr_l();
        break;
    case 0x86:
        ADDHL();
        break;
    case 0x87:
        ADDr_a();
        break;
    case 0x88:
        ADCr_b();
        break;
    case 0x89:
        ADCr_c();
        break;
    case 0x8A:
        ADCr_d();
        break;
    case 0x8B:
        ADCr_e();
        break;
    case 0x8C:
        ADCr_h();
        break;
    case 0x8D:
        ADCr_l();
        break;
    case 0x8E:
        ADCHL();
        break;
    case 0x8F:
        ADCr_a();
        break;
    case 0x90:
        SUBr_b();
        break;
    case 0x91:
        SUBr_c();
        break;
    case 0x92:
        SUBr_d();
        break;
    case 0x93:
        SUBr_e();
        break;
    case 0x94:
        SUBr_h();
        break;
    case 0x95:
        SUBr_l();
        break;
    case 0x96:
        SUBHL();
        break;
    case 0x97:
        SUBr_a();
        break;
    case 0x98:
        SBCr_b();
        break;
    case 0x99:
        SBCr_c();
        break;
    case 0x9A:
        SBCr_d();
        break;
    case 0x9B:
        SBCr_e();
        break;
    case 0x9C:
        SBCr_h();
        break;
    case 0x9D:
        SBCr_l();
        break;
    case 0x9E:
        SBCHL();
        break;
    case 0x9F:
        SBCr_a();
        break;
    case 0xA0:
        ANDr_b();
        break;
    case 0xA1:
        ANDr_c();
        break;
    case 0xA2:
        ANDr_d();
        break;
    case 0xA3:
        ANDr_e();
        break;
    case 0xA4:
        ANDr_h();
        break;
    case 0xA5:
        ANDr_l();
        break;
    case 0xA6:
        ANDHL();
        break;
    case 0xA7:
        ANDr_a();
        break;
    case 0xA8:
        XORr_b();
        break;
    case 0xA9:
        XORr_c();
        break;
    case 0xAA:
        XORr_d();
        break;
    case 0xAB:
        XORr_e();
        break;
    case 0xAC:
        XORr_h();
        break;
    case 0xAD:
        XORr_l();
        break;
    case 0xAE:
        XORHL();
        break;
    case 0xAF:
        XORr_a();
        break;
    case 0xB0:
        ORr_b();
        break;
    case 0xB1:
        ORr_c();
        break;
    case 0xB2:
        ORr_d();
        break;
    case 0xB3:
        ORr_e();
        break;
    case 0xB4:
        ORr_h();
        break;
    case 0xB5:
        ORr_l();
        break;
    case 0xB6:
        ORHL();
        break;
    case 0xB7:
        ORr_a();
        break;
    case 0xB8:
        CPr_b();
        break;
    case 0xB9:
        CPr_c();
        break;
    case 0xBA:
        CPr_d();
        break;
    case 0xBB:
        CPr_e();
        break;
    case 0xBC:
        CPr_h();
        break;
    case 0xBD:
        CPr_l();
        break;
    case 0xBE:
        CPHL();
        break;
    case 0xBF:
        CPr_a();
        break;
    case 0xC0:
        RETNZ();
        break;
    case 0xC1:
        POPBC();
        break;
    case 0xC2:
        JPNZnn();
        break;
    case 0xC3:
        JPnn();
        break;
    case 0xC4:
        CALLNZnn();
        break;
    case 0xC5:
        PUSHBC();
        break;
    case 0xC6:
        ADDn();
        break;
    case 0xC7:
        RST00();
        break;
    case 0xC8:
        RETZ();
        break;
    case 0xC9:
        RET();
        break;
    case 0xCA:
        JPZnn();
        break;
    case 0xCB:
        MAPcb();
        break;
    case 0xCC:
        CALLZnn();
        break;
    case 0xCD:
        CALLnn();
        break;
    case 0xCE:
        ADCn();
        break;
    case 0xCF:
        RST08();
        break;
    case 0xD0:
        RETNC();
        break;
    case 0xD1:
        POPDE();
        break;
    case 0xD2:
        JPNCnn();
        break;
    case 0xD3:
        XX();
        break;
    case 0xD4:
        CALLNCnn();
        break;
    case 0xD5:
        PUSHDE();
        break;
    case 0xD6:
        SUBn();
        break;
    case 0xD7:
        RST10();
        break;
    case 0xD8:
        RETC();
        break;
    case 0xD9:
        RETI();
        break;
    case 0xDA:
        JPCnn();
        break;
    case 0xDB:
        XX();
        break;
    case 0xDC:
        CALLCnn();
        break;
    case 0xDD:
        XX();
        break;
    case 0xDE:
        SBCn();
        break;
    case 0xDF:
        RST18();
        break;
    case 0xE0:
        LDIOnA();
        break;
    case 0xE1:
        POPHL();
        break;
    case 0xE2:
        LDIOCA();
        break;
    case 0xE3:
        XX();
        break;
    case 0xE4:
        XX();
        break;
    case 0xE5:
        PUSHHL();
        break;
    case 0xE6:
        ANDn();
        break;
    case 0xE7:
        RST20();
        break;
    case 0xE8:
        ADDSPn();
        break;
    case 0xE9:
        JPHL();
        break;
    case 0xEA:
        LDmmA();
        break;
    case 0xEB:
        XX();
        break;
    case 0xEC:
        XX();
        break;
    case 0xED:
        XX();
        break;
    case 0xEE:
        XORn();
        break;
    case 0xEF:
        RST28();
        break;
    case 0xF0:
        LDAIOn();
        break;
    case 0xF1:
        POPAF();
        break;
    case 0xF2:
        LDAIOC();
        break;
    case 0xF3:
        DI();
        break;
    case 0xF4:
        XX();
        break;
    case 0xF5:
        PUSHAF();
        break;
    case 0xF6:
        ORn();
        break;
    case 0xF7:
        RST30();
        break;
    case 0xF8:
        LDHLSPn();
        break;
    case 0xF9:
        XX();
        break;
    case 0xFA:
        LDAmm();
        break;
    case 0xFB:
        EI();
        break;
    case 0xFC:
        XX();
        break;
    case 0xFD:
        XX();
        break;
    case 0xFE:
        CPn();
        break;
    case 0xFF:
        RST38();
        break;
    default:
        throw std::runtime_error("OpCode: '" + ToHexString(op_code) + "'\n");
    }
}

void CPU::ExecuteCBInstruction(uint8_t op_code)
{
    switch (op_code)
    {
    case 0x00:
        RLCr_b();
        break;
    case 0x01:
        RLCr_c();
        break;
    case 0x02:
        RLCr_d();
        break;
    case 0x03:
        RLCr_e();
        break;
    case 0x04:
        RLCr_h();
        break;
    case 0x05:
        RLCr_l();
        break;
    case 0x06:
        RLCHL();
        break;
    case 0x07:
        RLCr_a();
        break;
    case 0x08:
        RRCr_b();
        break;
    case 0x09:
        RRCr_c();
        break;
    case 0x0A:
        RRCr_d();
        break;
    case 0x0B:
        RRCr_e();
        break;
    case 0x0C:
        RRCr_h();
        break;
    case 0x0D:
        RRCr_l();
        break;
    case 0x0E:
        RRCHL();
        break;
    case 0x0F:
        RRCr_a();
        break;
    case 0x10:
        RLr_b();
        break;
    case 0x11:
        RLr_c();
        break;
    case 0x12:
        RLr_d();
        break;
    case 0x13:
        RLr_e();
        break;
    case 0x14:
        RLr_h();
        break;
    case 0x15:
        RLr_l();
        break;
    case 0x16:
        RLHL();
        break;
    case 0x17:
        RLr_a();
        break;
    case 0x18:
        RRr_b();
        break;
    case 0x19:
        RRr_c();
        break;
    case 0x1A:
        RRr_d();
        break;
    case 0x1B:
        RRr_e();
        break;
    case 0x1C:
        RRr_h();
        break;
    case 0x1D:
        RRr_l();
        break;
    case 0x1E:
        RRHL();
        break;
    case 0x1F:
        RRr_a();
        break;
    case 0x20:
        SLAr_b();
        break;
    case 0x21:
        SLAr_c();
        break;
    case 0x22:
        SLAr_d();
        break;
    case 0x23:
        SLAr_e();
        break;
    case 0x24:
        SLAr_h();
        break;
    case 0x25:
        SLAr_l();
        break;
    case 0x26:
        XX();
        break;
    case 0x27:
        SLAr_a();
        break;
    case 0x28:
        SRAr_b();
        break;
    case 0x29:
        SRAr_c();
        break;
    case 0x2A:
        SRAr_d();
        break;
    case 0x2B:
        SRAr_e();
        break;
    case 0x2C:
        SRAr_h();
        break;
    case 0x2D:
        SRAr_l();
        break;
    case 0x2E:
        XX();
        break;
    case 0x2F:
        SRAr_a();
        break;
    case 0x30:
        SWAPr_b();
        break;
    case 0x31:
        SWAPr_c();
        break;
    case 0x32:
        SWAPr_d();
        break;
    case 0x33:
        SWAPr_e();
        break;
    case 0x34:
        SWAPr_h();
        break;
    case 0x35:
        SWAPr_l();
        break;
    case 0x36:
        XX();
        break;
    case 0x37:
        SWAPr_a();
        break;
    case 0x38:
        SRLr_b();
        break;
    case 0x39:
        SRLr_c();
        break;
    case 0x3A:
        SRLr_d();
        break;
    case 0x3B:
        SRLr_e();
        break;
    case 0x3C:
        SRLr_h();
        break;
    case 0x3D:
        SRLr_l();
        break;
    case 0x3E:
        XX();
        break;
    case 0x3F:
        SRLr_a();
        break;
    case 0x40:
        BIT0b();
        break;
    case 0x41:
        BIT0c();
        break;
    case 0x42:
        BIT0d();
        break;
    case 0x43:
        BIT0e();
        break;
    case 0x44:
        BIT0h();
        break;
    case 0x45:
        BIT0l();
        break;
    case 0x46:
        BIT0m();
        break;
    case 0x47:
        BIT0a();
        break;
    case 0x48:
        BIT1b();
        break;
    case 0x49:
        BIT1c();
        break;
    case 0x4A:
        BIT1d();
        break;
    case 0x4B:
        BIT1e();
        break;
    case 0x4C:
        BIT1h();
        break;
    case 0x4D:
        BIT1l();
        break;
    case 0x4E:
        BIT1m();
        break;
    case 0x4F:
        BIT1a();
        break;
    case 0x50:
        BIT2b();
        break;
    case 0x51:
        BIT2c();
        break;
    case 0x52:
        BIT2d();
        break;
    case 0x53:
        BIT2e();
        break;
    case 0x54:
        BIT2h();
        break;
    case 0x55:
        BIT2l();
        break;
    case 0x56:
        BIT2m();
        break;
    case 0x57:
        BIT2a();
        break;
    case 0x58:
        BIT3b();
        break;
    case 0x59:
        BIT3c();
        break;
    case 0x5A:
        BIT3d();
        break;
    case 0x5B:
        BIT3e();
        break;
    case 0x5C:
        BIT3h();
        break;
    case 0x5D:
        BIT3l();
        break;
    case 0x5E:
        BIT3m();
        break;
    case 0x5F:
        BIT3a();
        break;
    case 0x60:
        BIT4b();
        break;
    case 0x61:
        BIT4c();
        break;
    case 0x62:
        BIT4d();
        break;
    case 0x63:
        BIT4e();
        break;
    case 0x64:
        BIT4h();
        break;
    case 0x65:
        BIT4l();
        break;
    case 0x66:
        BIT4m();
        break;
    case 0x67:
        BIT4a();
        break;
    case 0x68:
        BIT5b();
        break;
    case 0x69:
        BIT5c();
        break;
    case 0x6A:
        BIT5d();
        break;
    case 0x6B:
        BIT5e();
        break;
    case 0x6C:
        BIT5h();
        break;
    case 0x6D:
        BIT5l();
        break;
    case 0x6E:
        BIT5m();
        break;
    case 0x6F:
        BIT5a();
        break;
    case 0x70:
        BIT6b();
        break;
    case 0x71:
        BIT6c();
        break;
    case 0x72:
        BIT6d();
        break;
    case 0x73:
        BIT6e();
        break;
    case 0x74:
        BIT6h();
        break;
    case 0x75:
        BIT6l();
        break;
    case 0x76:
        BIT6m();
        break;
    case 0x77:
        BIT6a();
        break;
    case 0x78:
        BIT7b();
        break;
    case 0x79:
        BIT7c();
        break;
    case 0x7A:
        BIT7d();
        break;
    case 0x7B:
        BIT7e();
        break;
    case 0x7C:
        BIT7h();
        break;
    case 0x7D:
        BIT7l();
        break;
    case 0x7E:
        BIT7m();
        break;
    case 0x7F:
        BIT7a();
        break;
    case 0x80:
        RES0b();
        break;
    case 0x81:
        RES0c();
        break;
    case 0x82:
        RES0d();
        break;
    case 0x83:
        RES0e();
        break;
    case 0x84:
        RES0h();
        break;
    case 0x85:
        RES0l();
        break;
    case 0x86:
        RES0m();
        break;
    case 0x87:
        RES0a();
        break;
    case 0x88:
        RES1b();
        break;
    case 0x89:
        RES1c();
        break;
    case 0x8A:
        RES1d();
        break;
    case 0x8B:
        RES1e();
        break;
    case 0x8C:
        RES1h();
        break;
    case 0x8D:
        RES1l();
        break;
    case 0x8E:
        RES1m();
        break;
    case 0x8F:
        RES1a();
        break;
    case 0x90:
        RES2b();
        break;
    case 0x91:
        RES2c();
        break;
    case 0x92:
        RES2d();
        break;
    case 0x93:
        RES2e();
        break;
    case 0x94:
        RES2h();
        break;
    case 0x95:
        RES2l();
        break;
    case 0x96:
        RES2m();
        break;
    case 0x97:
        RES2a();
        break;
    case 0x98:
        RES3b();
        break;
    case 0x99:
        RES3c();
        break;
    case 0x9A:
        RES3d();
        break;
    case 0x9B:
        RES3e();
        break;
    case 0x9C:
        RES3h();
        break;
    case 0x9D:
        RES3l();
        break;
    case 0x9E:
        RES3m();
        break;
    case 0x9F:
        RES3a();
        break;
    case 0xA0:
        RES4b();
        break;
    case 0xA1:
        RES4c();
        break;
    case 0xA2:
        RES4d();
        break;
    case 0xA3:
        RES4e();
        break;
    case 0xA4:
        RES4h();
        break;
    case 0xA5:
        RES4l();
        break;
    case 0xA6:
        RES4m();
        break;
    case 0xA7:
        RES4a();
        break;
    case 0xA8:
        RES5b();
        break;
    case 0xA9:
        RES5c();
        break;
    case 0xAA:
        RES5d();
        break;
    case 0xAB:
        RES5e();
        break;
    case 0xAC:
        RES5h();
        break;
    case 0xAD:
        RES5l();
        break;
    case 0xAE:
        RES5m();
        break;
    case 0xAF:
        RES5a();
        break;
    case 0xB0:
        RES6b();
        break;
    case 0xB1:
        RES6c();
        break;
    case 0xB2:
        RES6d();
        break;
    case 0xB3:
        RES6e();
        break;
    case 0xB4:
        RES6h();
        break;
    case 0xB5:
        RES6l();
        break;
    case 0xB6:
        RES6m();
        break;
    case 0xB7:
        RES6a();
        break;
    case 0xB8:
        RES7b();
        break;
    case 0xB9:
        RES7c();
        break;
    case 0xBA:
        RES7d();
        break;
    case 0xBB:
        RES7e();
        break;
    case 0xBC:
        RES7h();
        break;
    case 0xBD:
        RES7l();
        break;
    case 0xBE:
        RES7m();
        break;
    case 0xBF:
        RES7a();
        break;
    case 0xC0:
        SET0b();
        break;
    case 0xC1:
        SET0c();
        break;
    case 0xC2:
        SET0d();
        break;
    case 0xC3:
        SET0e();
        break;
    case 0xC4:
        SET0h();
        break;
    case 0xC5:
        SET0l();
        break;
    case 0xC6:
        SET0m();
        break;
    case 0xC7:
        SET0a();
        break;
    case 0xC8:
        SET1b();
        break;
    case 0xC9:
        SET1c();
        break;
    case 0xCA:
        SET1d();
        break;
    case 0xCB:
        SET1e();
        break;
    case 0xCC:
        SET1h();
        break;
    case 0xCD:
        SET1l();
        break;
    case 0xCE:
        SET1m();
        break;
    case 0xCF:
        SET1a();
        break;
    case 0xD0:
        SET2b();
        break;
    case 0xD1:
        SET2c();
        break;
    case 0xD2:
        SET2d();
        break;
    case 0xD3:
        SET2e();
        break;
    case 0xD4:
        SET2h();
        break;
    case 0xD5:
        SET2l();
        break;
    case 0xD6:
        SET2m();
        break;
    case 0xD7:
        SET2a();
        break;
    case 0xD8:
        SET3b();
        break;
    case 0xD9:
        SET3c();
        break;
    case 0xDA:
        SET3d();
        break;
    case 0xDB:
        SET3e();
        break;
    case 0xDC:
        SET3h();
        break;
    case 0xDD:
        SET3l();
        break;
    case 0xDE:
        SET3m();
        break;
    case 0xDF:
        SET3a();
        break;
    case 0xE0:
        SET4b();
        break;
    case 0xE1:
        SET4c();
        break;
    case 0xE2:
        SET4d();
        break;
    case 0xE3:
        SET4e();
        break;
    case 0xE4:
        SET4h();
        break;
    case 0xE5:
        SET4l();
        break;
    case 0xE6:
        SET4m();
        break;
    case 0xE7:
        SET4a();
        break;
    case 0xE8:
        SET5b();
        break;
    case 0xE9:
        SET5c();
        break;
    case 0xEA:
        SET5d();
        break;
    case 0xEB:
        SET5e();
        break;
    case 0xEC:
        SET5h();
        break;
    case 0xED:
        SET5l();
        break;
    case 0xEE:
        SET5m();
        break;
    case 0xEF:
        SET5a();
        break;
    case 0xF0:
        SET6b();
        break;
    case 0xF1:
        SET6c();
        break;
    case 0xF2:
        SET6d();
        break;
    case 0xF3:
        SET6e();
        break;
    case 0xF4:
        SET6h();
        break;
    case 0xF5:
        SET6l();
        break;
    case 0xF6:
        SET6m();
        break;
    case 0xF7:
        SET6a();
        break;
    case 0xF8:
        SET7b();
        break;
    case 0xF9:
        SET7c();
        break;
    case 0xFA:
        SET7d();
        break;
    case 0xFB:
        SET7e();
        break;
    case 0xFC:
        SET7h();
        break;
    case 0xFD:
        SET7l();
        break;
    case 0xFE:
        SET7m();
        break;
    case 0xFF:
        SET7a();
        break;
    default:
        throw std::runtime_error("CB OpCode: '" + ToHexString(op_code) + "'\n");
    }
}

uint16_t CPU::GetNextPC()
{
    return registers.pc++;
}

uint16_t CPU::GetCurrentPC() const
{
    return registers.pc;
}

void CPU::SetMMU(MMU &mmu)
{
    this->mmu = &mmu;
}

void CPU::UpdateClock()
{
    clock.m += registers.m;
    clock.t += registers.t;
}

void CPU::Reset()
{
    registers.a = 0;
    registers.b = 0;
    registers.c = 0;
    registers.d = 0;
    registers.e = 0;
    registers.h = 0;
    registers.l = 0;
    registers.f = 0;
    registers.sp = 0;
    registers.pc = 0;
    registers.m = 0;
    registers.t = 0;
    clock.m = 0;
    clock.t = 0;
}

// cpu functions

void CPU::LDrr_bb()
{
    registers.b = registers.b;
    registers.m = 1;
}
void CPU::LDrr_bc()
{
    registers.b = registers.c;
    registers.m = 1;
}
void CPU::LDrr_bd()
{
    registers.b = registers.d;
    registers.m = 1;
}
void CPU::LDrr_be()
{
    registers.b = registers.e;
    registers.m = 1;
}
void CPU::LDrr_bh()
{
    registers.b = registers.h;
    registers.m = 1;
}
void CPU::LDrr_bl()
{
    registers.b = registers.l;
    registers.m = 1;
}
void CPU::LDrr_ba()
{
    registers.b = registers.a;
    registers.m = 1;
}
void CPU::LDrr_cb()
{
    registers.c = registers.b;
    registers.m = 1;
}
void CPU::LDrr_cc()
{
    registers.c = registers.c;
    registers.m = 1;
}
void CPU::LDrr_cd()
{
    registers.c = registers.d;
    registers.m = 1;
}
void CPU::LDrr_ce()
{
    registers.c = registers.e;
    registers.m = 1;
}
void CPU::LDrr_ch()
{
    registers.c = registers.h;
    registers.m = 1;
}
void CPU::LDrr_cl()
{
    registers.c = registers.l;
    registers.m = 1;
}
void CPU::LDrr_ca()
{
    registers.c = registers.a;
    registers.m = 1;
}
void CPU::LDrr_db()
{
    registers.d = registers.b;
    registers.m = 1;
}
void CPU::LDrr_dc()
{
    registers.d = registers.c;
    registers.m = 1;
}
void CPU::LDrr_dd()
{
    registers.d = registers.d;
    registers.m = 1;
}
void CPU::LDrr_de()
{
    registers.d = registers.e;
    registers.m = 1;
}
void CPU::LDrr_dh()
{
    registers.d = registers.h;
    registers.m = 1;
}
void CPU::LDrr_dl()
{
    registers.d = registers.l;
    registers.m = 1;
}
void CPU::LDrr_da()
{
    registers.d = registers.a;
    registers.m = 1;
}
void CPU::LDrr_eb()
{
    registers.e = registers.b;
    registers.m = 1;
}
void CPU::LDrr_ec()
{
    registers.e = registers.c;
    registers.m = 1;
}
void CPU::LDrr_ed()
{
    registers.e = registers.d;
    registers.m = 1;
}
void CPU::LDrr_ee()
{
    registers.e = registers.e;
    registers.m = 1;
}
void CPU::LDrr_eh()
{
    registers.e = registers.h;
    registers.m = 1;
}
void CPU::LDrr_el()
{
    registers.e = registers.l;
    registers.m = 1;
}
void CPU::LDrr_ea()
{
    registers.e = registers.a;
    registers.m = 1;
}
void CPU::LDrr_hb()
{
    registers.h = registers.b;
    registers.m = 1;
}
void CPU::LDrr_hc()
{
    registers.h = registers.c;
    registers.m = 1;
}
void CPU::LDrr_hd()
{
    registers.h = registers.d;
    registers.m = 1;
}
void CPU::LDrr_he()
{
    registers.h = registers.e;
    registers.m = 1;
}
void CPU::LDrr_hh()
{
    registers.h = registers.h;
    registers.m = 1;
}
void CPU::LDrr_hl()
{
    registers.h = registers.l;
    registers.m = 1;
}
void CPU::LDrr_ha()
{
    registers.h = registers.a;
    registers.m = 1;
}
void CPU::LDrr_lb()
{
    registers.l = registers.b;
    registers.m = 1;
}
void CPU::LDrr_lc()
{
    registers.l = registers.c;
    registers.m = 1;
}
void CPU::LDrr_ld()
{
    registers.l = registers.d;
    registers.m = 1;
}
void CPU::LDrr_le()
{
    registers.l = registers.e;
    registers.m = 1;
}
void CPU::LDrr_lh()
{
    registers.l = registers.h;
    registers.m = 1;
}
void CPU::LDrr_ll()
{
    registers.l = registers.l;
    registers.m = 1;
}
void CPU::LDrr_la()
{
    registers.l = registers.a;
    registers.m = 1;
}
void CPU::LDrr_ab()
{
    registers.a = registers.b;
    registers.m = 1;
}
void CPU::LDrr_ac()
{
    registers.a = registers.c;
    registers.m = 1;
}
void CPU::LDrr_ad()
{
    registers.a = registers.d;
    registers.m = 1;
}
void CPU::LDrr_ae()
{
    registers.a = registers.e;
    registers.m = 1;
}
void CPU::LDrr_ah()
{
    registers.a = registers.h;
    registers.m = 1;
}
void CPU::LDrr_al()
{
    registers.a = registers.l;
    registers.m = 1;
}
void CPU::LDrr_aa()
{
    registers.a = registers.a;
    registers.m = 1;
}

void CPU::LDrHLm_b()
{
    registers.b = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.m = 2;
}
void CPU::LDrHLm_c()
{
    registers.c = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.m = 2;
}
void CPU::LDrHLm_d()
{
    registers.d = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.m = 2;
}
void CPU::LDrHLm_e()
{
    registers.e = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.m = 2;
}
void CPU::LDrHLm_h()
{
    registers.h = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.m = 2;
}
void CPU::LDrHLm_l()
{
    registers.l = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.m = 2;
}
void CPU::LDrHLm_a()
{
    registers.a = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.m = 2;
}

void CPU::LDHLmr_b()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.b);
    registers.m = 2;
}
void CPU::LDHLmr_c()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.c);
    registers.m = 2;
}
void CPU::LDHLmr_d()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.d);
    registers.m = 2;
}
void CPU::LDHLmr_e()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.e);
    registers.m = 2;
}
void CPU::LDHLmr_h()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.h);
    registers.m = 2;
}
void CPU::LDHLmr_l()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.l);
    registers.m = 2;
}
void CPU::LDHLmr_a()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.a);
    registers.m = 2;
}

void CPU::LDrn_b()
{
    registers.b = mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.m = 2;
}
void CPU::LDrn_c()
{
    registers.c = mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.m = 2;
}
void CPU::LDrn_d()
{
    registers.d = mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.m = 2;
}
void CPU::LDrn_e()
{
    registers.e = mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.m = 2;
}
void CPU::LDrn_h()
{
    registers.h = mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.m = 2;
}
void CPU::LDrn_l()
{
    registers.l = mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.m = 2;
}
void CPU::LDrn_a()
{
    registers.a = mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.m = 2;
}

void CPU::LDHLmn()
{
    mmu->WriteByte((registers.h << 8) + registers.l, mmu->ReadByte(registers.pc));
    registers.pc++;
    registers.m = 3;
}

void CPU::LDBCmA()
{
    mmu->WriteByte((registers.b << 8) + registers.c, registers.a);
    registers.m = 2;
}
void CPU::LDDEmA()
{
    mmu->WriteByte((registers.d << 8) + registers.e, registers.a);
    registers.m = 2;
}

void CPU::LDmmA()
{
    mmu->WriteByte(mmu->ReadWord(registers.pc), registers.a);
    registers.pc += 2;
    registers.m = 4;
}

void CPU::LDABCm()
{
    registers.a = mmu->ReadByte((registers.b << 8) + registers.c);
    registers.m = 2;
}
void CPU::LDADEm()
{
    registers.a = mmu->ReadByte((registers.d << 8) + registers.e);
    registers.m = 2;
}

void CPU::LDAmm()
{
    registers.a = mmu->ReadByte(mmu->ReadWord(registers.pc));
    registers.pc += 2;
    registers.m = 4;
}

void CPU::LDBCnn()
{
    registers.c = mmu->ReadByte(registers.pc);
    registers.b = mmu->ReadByte(registers.pc + 1);
    registers.pc += 2;
    registers.m = 3;
}
void CPU::LDDEnn()
{
    registers.e = mmu->ReadByte(registers.pc);
    registers.d = mmu->ReadByte(registers.pc + 1);
    registers.pc += 2;
    registers.m = 3;
}
void CPU::LDHLnn()
{
    registers.l = mmu->ReadByte(registers.pc);
    registers.h = mmu->ReadByte(registers.pc + 1);
    registers.pc += 2;
    registers.m = 3;
}
void CPU::LDSPnn()
{
    registers.sp = mmu->ReadWord(registers.pc);
    registers.pc += 2;
    registers.m = 3;
}

void CPU::LDHLmm()
{
    auto i = mmu->ReadWord(registers.pc);
    registers.pc += 2;
    registers.l = mmu->ReadByte(i);
    registers.h = mmu->ReadByte(i + 1);
    registers.m = 5;
}
void CPU::LDmmHL()
{
    auto i = mmu->ReadWord(registers.pc);
    registers.pc += 2;
    mmu->WriteWord(i, (registers.h << 8) + registers.l);
    registers.m = 5;
}

void CPU::LDHLIA()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.a);
    registers.l = (registers.l + 1) & 255;
    if (!registers.l)
        registers.h = (registers.h + 1) & 255;
    registers.m = 2;
}
void CPU::LDAHLI()
{
    registers.a = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.l = (registers.l + 1) & 255;
    if (!registers.l)
        registers.h = (registers.h + 1) & 255;
    registers.m = 2;
}

void CPU::LDHLDA()
{
    mmu->WriteByte((registers.h << 8) + registers.l, registers.a);
    registers.l = (registers.l - 1) & 255;
    if (registers.l == 255)
        registers.h = (registers.h - 1) & 255;
    registers.m = 2;
}
void CPU::LDAHLD()
{
    registers.a = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.l = (registers.l - 1) & 255;
    if (registers.l == 255)
        registers.h = (registers.h - 1) & 255;
    registers.m = 2;
}

void CPU::LDAIOn()
{
    registers.a = mmu->ReadByte(0xFF00 + mmu->ReadByte(registers.pc));
    registers.pc++;
    registers.m = 3;
}
void CPU::LDIOnA()
{
    mmu->WriteByte(0xFF00 + mmu->ReadByte(registers.pc), registers.a);
    registers.pc++;
    registers.m = 3;
}
void CPU::LDAIOC()
{
    registers.a = mmu->ReadByte(0xFF00 + registers.c);
    registers.m = 2;
}
void CPU::LDIOCA()
{
    mmu->WriteByte(0xFF00 + registers.c, registers.a);
    registers.m = 2;
}

void CPU::LDHLSPn()
{
    int8_t i = mmu->ReadByte(registers.pc);
    if (i > 127)
        i = -((~i + 1) & 255);
    registers.pc++;
    i += registers.sp;
    registers.h = (i >> 8) & 255;
    registers.l = i & 255;
    registers.m = 3;
}

void CPU::SWAPr_b()
{
    auto tr = registers.b;
    registers.b = ((tr & 0xF) << 4) | ((tr & 0xF0) >> 4);
    registers.f = registers.b ? 0 : 0x80;
    registers.m = 1;
}
void CPU::SWAPr_c()
{
    auto tr = registers.c;
    registers.c = ((tr & 0xF) << 4) | ((tr & 0xF0) >> 4);
    registers.f = registers.c ? 0 : 0x80;
    registers.m = 1;
}
void CPU::SWAPr_d()
{
    auto tr = registers.d;
    registers.d = ((tr & 0xF) << 4) | ((tr & 0xF0) >> 4);
    registers.f = registers.d ? 0 : 0x80;
    registers.m = 1;
}
void CPU::SWAPr_e()
{
    auto tr = registers.e;
    registers.e = ((tr & 0xF) << 4) | ((tr & 0xF0) >> 4);
    registers.f = registers.e ? 0 : 0x80;
    registers.m = 1;
}
void CPU::SWAPr_h()
{
    auto tr = registers.h;
    registers.h = ((tr & 0xF) << 4) | ((tr & 0xF0) >> 4);
    registers.f = registers.h ? 0 : 0x80;
    registers.m = 1;
}
void CPU::SWAPr_l()
{
    auto tr = registers.l;
    registers.l = ((tr & 0xF) << 4) | ((tr & 0xF0) >> 4);
    registers.f = registers.l ? 0 : 0x80;
    registers.m = 1;
}
void CPU::SWAPr_a()
{
    auto tr = registers.a;
    registers.a = ((tr & 0xF) << 4) | ((tr & 0xF0) >> 4);
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}

/*--- Data processing ---*/
void CPU::ADDr_b()
{
    auto a = registers.a;
    registers.a += registers.b;
    registers.f = (registers.a < a) ? 0x10 : 0;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.b ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADDr_c()
{
    auto a = registers.a;
    registers.a += registers.c;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.c ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADDr_d()
{
    auto a = registers.a;
    registers.a += registers.d;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.d ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADDr_e()
{
    auto a = registers.a;
    registers.a += registers.e;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.e ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADDr_h()
{
    auto a = registers.a;
    registers.a += registers.h;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.h ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADDr_l()
{
    auto a = registers.a;
    registers.a += registers.l;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.l ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADDr_a()
{
    auto a = registers.a;
    registers.a += registers.a;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.a ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADDHL()
{
    auto a = registers.a;
    auto m = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.a += m;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ a ^ m) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}
void CPU::ADDn()
{
    auto a = registers.a;
    auto m = mmu->ReadByte(registers.pc);
    registers.a += m;
    registers.pc++;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ a ^ m) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}
void CPU::ADDHLBC()
{
    auto hl = (registers.h << 8) + registers.l;
    hl += (registers.b << 8) + registers.c;
    if (hl > 65535)
        registers.f |= 0x10;
    else
        registers.f &= 0xEF;
    registers.h = (hl >> 8) & 255;
    registers.l = hl & 255;
    registers.m = 3;
}
void CPU::ADDHLDE()
{
    auto hl = (registers.h << 8) + registers.l;
    hl += (registers.d << 8) + registers.e;
    if (hl > 65535)
        registers.f |= 0x10;
    else
        registers.f &= 0xEF;
    registers.h = (hl >> 8) & 255;
    registers.l = hl & 255;
    registers.m = 3;
}
void CPU::ADDHLHL()
{
    auto hl = (registers.h << 8) + registers.l;
    hl += (registers.h << 8) + registers.l;
    if (hl > 65535)
        registers.f |= 0x10;
    else
        registers.f &= 0xEF;
    registers.h = (hl >> 8) & 255;
    registers.l = hl & 255;
    registers.m = 3;
}
void CPU::ADDHLSP()
{
    auto hl = (registers.h << 8) + registers.l;
    hl += registers.sp;
    if (hl > 65535)
        registers.f |= 0x10;
    else
        registers.f &= 0xEF;
    registers.h = (hl >> 8) & 255;
    registers.l = hl & 255;
    registers.m = 3;
}
void CPU::ADDSPn()
{
    int8_t i = mmu->ReadByte(registers.pc);
    if (i > 127)
        i = -((~i + 1) & 255);
    registers.pc++;
    registers.sp += i;
    registers.m = 4;
}

void CPU::ADCr_b()
{
    auto a = registers.a;
    registers.a += registers.b;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.b ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADCr_c()
{
    auto a = registers.a;
    registers.a += registers.c;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.c ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADCr_d()
{
    auto a = registers.a;
    registers.a += registers.d;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.d ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADCr_e()
{
    auto a = registers.a;
    registers.a += registers.e;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.e ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADCr_h()
{
    auto a = registers.a;
    registers.a += registers.h;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.h ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADCr_l()
{
    auto a = registers.a;
    registers.a += registers.l;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.l ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADCr_a()
{
    auto a = registers.a;
    registers.a += registers.a;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.a ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::ADCHL()
{
    auto a = registers.a;
    auto m = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.a += m;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ m ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}
void CPU::ADCn()
{
    auto a = registers.a;
    auto m = mmu->ReadByte(registers.pc);
    registers.a += m;
    registers.pc++;
    registers.a += (registers.f & 0x10) ? 1 : 0;
    registers.f = (registers.a < a) ? 0x10 : 0;;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ m ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}

void CPU::SUBr_b()
{
    auto a = registers.a;
    registers.a -= registers.b;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.b ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SUBr_c()
{
    auto a = registers.a;
    registers.a -= registers.c;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.c ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SUBr_d()
{
    auto a = registers.a;
    registers.a -= registers.d;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.d ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SUBr_e()
{
    auto a = registers.a;
    registers.a -= registers.e;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.e ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SUBr_h()
{
    auto a = registers.a;
    registers.a -= registers.h;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.h ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SUBr_l()
{
    auto a = registers.a;
    registers.a -= registers.l;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.l ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SUBr_a()
{
    auto a = registers.a;
    registers.a -= registers.a;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.a ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SUBHL()
{
    auto a = registers.a;
    auto m = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.a -= m;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ m ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}
void CPU::SUBn()
{
    auto a = registers.a;
    auto m = mmu->ReadByte(registers.pc);
    registers.a -= m;
    registers.pc++;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ m ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}

void CPU::SBCr_b()
{
    auto a = registers.a;
    registers.a -= registers.b;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.b ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SBCr_c()
{
    auto a = registers.a;
    registers.a -= registers.c;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.c ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SBCr_d()
{
    auto a = registers.a;
    registers.a -= registers.d;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.d ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SBCr_e()
{
    auto a = registers.a;
    registers.a -= registers.e;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.e ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SBCr_h()
{
    auto a = registers.a;
    registers.a -= registers.h;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.h ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SBCr_l()
{
    auto a = registers.a;
    registers.a -= registers.l;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.l ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SBCr_a()
{
    auto a = registers.a;
    registers.a -= registers.a;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ registers.a ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::SBCHL()
{
    auto a = registers.a;
    auto m = mmu->ReadByte((registers.h << 8) + registers.l);
    registers.a -= m;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ m ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}
void CPU::SBCn()
{
    auto a = registers.a;
    auto m = mmu->ReadByte(registers.pc);
    registers.a -= m;
    registers.pc++;
    registers.a -= (registers.f & 0x10) ? 1 : 0;
    registers.f = (a < registers.a) ? 0x50 : 0x40;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    if ((registers.a ^ m ^ a) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}

void CPU::CPr_b()
{
    int16_t i = registers.a;
    i -= registers.b;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ registers.b ^ i) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::CPr_c()
{
    int16_t i = registers.a;
    i -= registers.c;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ registers.c ^ i) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::CPr_d()
{
    int16_t i = registers.a;
    i -= registers.d;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ registers.d ^ i) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::CPr_e()
{
    int16_t i = registers.a;
    i -= registers.e;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ registers.e ^ i) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::CPr_h()
{
    int16_t i = registers.a;
    i -= registers.h;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ registers.h ^ i) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::CPr_l()
{
    int16_t i = registers.a;
    i -= registers.l;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ registers.l ^ i) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::CPr_a()
{
    int16_t i = registers.a;
    i -= registers.a;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ registers.a ^ i) & 0x10)
        registers.f |= 0x20;
    registers.m = 1;
}
void CPU::CPHL()
{
    int16_t i = registers.a;
    auto m = mmu->ReadByte((registers.h << 8) + registers.l);
    i -= m;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ i ^ m) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}
void CPU::CPn()
{
    int16_t i = registers.a;
    auto m = mmu->ReadByte(registers.pc);
    i -= m;
    registers.pc++;
    registers.f = (i < 0) ? 0x50 : 0x40;
    i &= 255;
    if (!i)
        registers.f |= 0x80;
    if ((registers.a ^ i ^ m) & 0x10)
        registers.f |= 0x20;
    registers.m = 2;
}

void CPU::DAA()
{
    auto a = registers.a;
    if ((registers.f & 0x20) || ((registers.a & 15) > 9))
        registers.a += 6;
    registers.f &= 0xEF;
    if ((registers.f & 0x20) || (a > 0x99))
    {
        registers.a += 0x60;
        registers.f |= 0x10;
    }
    registers.m = 1;
}

void CPU::ANDr_b()
{
    registers.a &= registers.b;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ANDr_c()
{
    registers.a &= registers.c;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ANDr_d()
{
    registers.a &= registers.d;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ANDr_e()
{
    registers.a &= registers.e;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ANDr_h()
{
    registers.a &= registers.h;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ANDr_l()
{
    registers.a &= registers.l;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ANDr_a()
{
    registers.a &= registers.a;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ANDHL()
{
    registers.a &= mmu->ReadByte((registers.h << 8) + registers.l);
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 2;
}
void CPU::ANDn()
{
    registers.a &= mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 2;
}

void CPU::ORr_b()
{
    registers.a |= registers.b;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ORr_c()
{
    registers.a |= registers.c;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ORr_d()
{
    registers.a |= registers.d;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ORr_e()
{
    registers.a |= registers.e;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ORr_h()
{
    registers.a |= registers.h;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ORr_l()
{
    registers.a |= registers.l;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ORr_a()
{
    registers.a |= registers.a;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::ORHL()
{
    registers.a |= mmu->ReadByte((registers.h << 8) + registers.l);
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 2;
}
void CPU::ORn()
{
    registers.a |= mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 2;
}

void CPU::XORr_b()
{
    registers.a ^= registers.b;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::XORr_c()
{
    registers.a ^= registers.c;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::XORr_d()
{
    registers.a ^= registers.d;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::XORr_e()
{
    registers.a ^= registers.e;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::XORr_h()
{
    registers.a ^= registers.h;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::XORr_l()
{
    registers.a ^= registers.l;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::XORr_a()
{
    registers.a ^= registers.a;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::XORHL()
{
    registers.a ^= mmu->ReadByte((registers.h << 8) + registers.l);
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 2;
}
void CPU::XORn()
{
    registers.a ^= mmu->ReadByte(registers.pc);
    registers.pc++;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 2;
}

void CPU::INCr_b()
{
    registers.b++;
    registers.b &= 255;
    registers.f = registers.b ? 0 : 0x80;
    registers.m = 1;
}
void CPU::INCr_c()
{
    registers.c++;
    registers.c &= 255;
    registers.f = registers.c ? 0 : 0x80;
    registers.m = 1;
}
void CPU::INCr_d()
{
    registers.d++;
    registers.d &= 255;
    registers.f = registers.d ? 0 : 0x80;
    registers.m = 1;
}
void CPU::INCr_e()
{
    registers.e++;
    registers.e &= 255;
    registers.f = registers.e ? 0 : 0x80;
    registers.m = 1;
}
void CPU::INCr_h()
{
    registers.h++;
    registers.h &= 255;
    registers.f = registers.h ? 0 : 0x80;
    registers.m = 1;
}
void CPU::INCr_l()
{
    registers.l++;
    registers.l &= 255;
    registers.f = registers.l ? 0 : 0x80;
    registers.m = 1;
}
void CPU::INCr_a()
{
    registers.a++;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::INCHLm()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l) + 1;
    i &= 255;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.f = i ? 0 : 0x80;
    registers.m = 3;
}

void CPU::DECr_b()
{
    registers.b--;
    registers.b &= 255;
    registers.f = registers.b ? 0 : 0x80;
    registers.m = 1;
}
void CPU::DECr_c()
{
    registers.c--;
    registers.c &= 255;
    registers.f = registers.c ? 0 : 0x80;
    registers.m = 1;
}
void CPU::DECr_d()
{
    registers.d--;
    registers.d &= 255;
    registers.f = registers.d ? 0 : 0x80;
    registers.m = 1;
}
void CPU::DECr_e()
{
    registers.e--;
    registers.e &= 255;
    registers.f = registers.e ? 0 : 0x80;
    registers.m = 1;
}
void CPU::DECr_h()
{
    registers.h--;
    registers.h &= 255;
    registers.f = registers.h ? 0 : 0x80;
    registers.m = 1;
}
void CPU::DECr_l()
{
    registers.l--;
    registers.l &= 255;
    registers.f = registers.l ? 0 : 0x80;
    registers.m = 1;
}
void CPU::DECr_a()
{
    registers.a--;
    registers.a &= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::DECHLm()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l) - 1;
    i &= 255;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.f = i ? 0 : 0x80;
    registers.m = 3;
}

void CPU::INCBC()
{
    registers.c = (registers.c + 1) & 255;
    if (!registers.c)
        registers.b = (registers.b + 1) & 255;
    registers.m = 1;
}
void CPU::INCDE()
{
    registers.e = (registers.e + 1) & 255;
    if (!registers.e)
        registers.d = (registers.d + 1) & 255;
    registers.m = 1;
}
void CPU::INCHL()
{
    registers.l = (registers.l + 1) & 255;
    if (!registers.l)
        registers.h = (registers.h + 1) & 255;
    registers.m = 1;
}
void CPU::INCSP()
{
    registers.sp = (registers.sp + 1) & 65535;
    registers.m = 1;
}

void CPU::DECBC()
{
    registers.c = (registers.c - 1) & 255;
    if (registers.c == 255)
        registers.b = (registers.b - 1) & 255;
    registers.m = 1;
}
void CPU::DECDE()
{
    registers.e = (registers.e - 1) & 255;
    if (registers.e == 255)
        registers.d = (registers.d - 1) & 255;
    registers.m = 1;
}
void CPU::DECHL()
{
    registers.l = (registers.l - 1) & 255;
    if (registers.l == 255)
        registers.h = (registers.h - 1) & 255;
    registers.m = 1;
}
void CPU::DECSP()
{
    registers.sp = (registers.sp - 1) & 65535;
    registers.m = 1;
}

/*--- Bit manipulation ---*/
void CPU::BIT0b()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.b & 0x01) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT0c()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.c & 0x01) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT0d()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.d & 0x01) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT0e()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.e & 0x01) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT0h()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.h & 0x01) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT0l()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.l & 0x01) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT0a()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.a & 0x01) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT0m()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (mmu->ReadByte((registers.h << 8) + registers.l) & 0x01) ? 0 : 0x80;
    registers.m = 3;
}

void CPU::RES0b()
{
    registers.b &= 0xFE;
    registers.m = 2;
}
void CPU::RES0c()
{
    registers.c &= 0xFE;
    registers.m = 2;
}
void CPU::RES0d()
{
    registers.d &= 0xFE;
    registers.m = 2;
}
void CPU::RES0e()
{
    registers.e &= 0xFE;
    registers.m = 2;
}
void CPU::RES0h()
{
    registers.h &= 0xFE;
    registers.m = 2;
}
void CPU::RES0l()
{
    registers.l &= 0xFE;
    registers.m = 2;
}
void CPU::RES0a()
{
    registers.a &= 0xFE;
    registers.m = 2;
}
void CPU::RES0m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i &= 0xFE;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::SET0b()
{
    registers.b |= 0x01;
    registers.m = 2;
}
void CPU::SET0c()
{
    registers.b |= 0x01;
    registers.m = 2;
}
void CPU::SET0d()
{
    registers.b |= 0x01;
    registers.m = 2;
}
void CPU::SET0e()
{
    registers.b |= 0x01;
    registers.m = 2;
}
void CPU::SET0h()
{
    registers.b |= 0x01;
    registers.m = 2;
}
void CPU::SET0l()
{
    registers.b |= 0x01;
    registers.m = 2;
}
void CPU::SET0a()
{
    registers.b |= 0x01;
    registers.m = 2;
}
void CPU::SET0m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i |= 0x01;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::BIT1b()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.b & 0x02) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT1c()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.c & 0x02) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT1d()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.d & 0x02) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT1e()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.e & 0x02) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT1h()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.h & 0x02) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT1l()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.l & 0x02) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT1a()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.a & 0x02) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT1m()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (mmu->ReadByte((registers.h << 8) + registers.l) & 0x02) ? 0 : 0x80;
    registers.m = 3;
}

void CPU::RES1b()
{
    registers.b &= 0xFD;
    registers.m = 2;
}
void CPU::RES1c()
{
    registers.c &= 0xFD;
    registers.m = 2;
}
void CPU::RES1d()
{
    registers.d &= 0xFD;
    registers.m = 2;
}
void CPU::RES1e()
{
    registers.e &= 0xFD;
    registers.m = 2;
}
void CPU::RES1h()
{
    registers.h &= 0xFD;
    registers.m = 2;
}
void CPU::RES1l()
{
    registers.l &= 0xFD;
    registers.m = 2;
}
void CPU::RES1a()
{
    registers.a &= 0xFD;
    registers.m = 2;
}
void CPU::RES1m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i &= 0xFD;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::SET1b()
{
    registers.b |= 0x02;
    registers.m = 2;
}
void CPU::SET1c()
{
    registers.b |= 0x02;
    registers.m = 2;
}
void CPU::SET1d()
{
    registers.b |= 0x02;
    registers.m = 2;
}
void CPU::SET1e()
{
    registers.b |= 0x02;
    registers.m = 2;
}
void CPU::SET1h()
{
    registers.b |= 0x02;
    registers.m = 2;
}
void CPU::SET1l()
{
    registers.b |= 0x02;
    registers.m = 2;
}
void CPU::SET1a()
{
    registers.b |= 0x02;
    registers.m = 2;
}
void CPU::SET1m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i |= 0x02;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::BIT2b()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.b & 0x04) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT2c()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.c & 0x04) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT2d()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.d & 0x04) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT2e()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.e & 0x04) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT2h()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.h & 0x04) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT2l()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.l & 0x04) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT2a()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.a & 0x04) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT2m()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (mmu->ReadByte((registers.h << 8) + registers.l) & 0x04) ? 0 : 0x80;
    registers.m = 3;
}

void CPU::RES2b()
{
    registers.b &= 0xFB;
    registers.m = 2;
}
void CPU::RES2c()
{
    registers.c &= 0xFB;
    registers.m = 2;
}
void CPU::RES2d()
{
    registers.d &= 0xFB;
    registers.m = 2;
}
void CPU::RES2e()
{
    registers.e &= 0xFB;
    registers.m = 2;
}
void CPU::RES2h()
{
    registers.h &= 0xFB;
    registers.m = 2;
}
void CPU::RES2l()
{
    registers.l &= 0xFB;
    registers.m = 2;
}
void CPU::RES2a()
{
    registers.a &= 0xFB;
    registers.m = 2;
}
void CPU::RES2m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i &= 0xFB;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::SET2b()
{
    registers.b |= 0x04;
    registers.m = 2;
}
void CPU::SET2c()
{
    registers.b |= 0x04;
    registers.m = 2;
}
void CPU::SET2d()
{
    registers.b |= 0x04;
    registers.m = 2;
}
void CPU::SET2e()
{
    registers.b |= 0x04;
    registers.m = 2;
}
void CPU::SET2h()
{
    registers.b |= 0x04;
    registers.m = 2;
}
void CPU::SET2l()
{
    registers.b |= 0x04;
    registers.m = 2;
}
void CPU::SET2a()
{
    registers.b |= 0x04;
    registers.m = 2;
}
void CPU::SET2m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i |= 0x04;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::BIT3b()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.b & 0x08) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT3c()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.c & 0x08) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT3d()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.d & 0x08) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT3e()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.e & 0x08) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT3h()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.h & 0x08) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT3l()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.l & 0x08) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT3a()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.a & 0x08) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT3m()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (mmu->ReadByte((registers.h << 8) + registers.l) & 0x08) ? 0 : 0x80;
    registers.m = 3;
}

void CPU::RES3b()
{
    registers.b &= 0xF7;
    registers.m = 2;
}
void CPU::RES3c()
{
    registers.c &= 0xF7;
    registers.m = 2;
}
void CPU::RES3d()
{
    registers.d &= 0xF7;
    registers.m = 2;
}
void CPU::RES3e()
{
    registers.e &= 0xF7;
    registers.m = 2;
}
void CPU::RES3h()
{
    registers.h &= 0xF7;
    registers.m = 2;
}
void CPU::RES3l()
{
    registers.l &= 0xF7;
    registers.m = 2;
}
void CPU::RES3a()
{
    registers.a &= 0xF7;
    registers.m = 2;
}
void CPU::RES3m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i &= 0xF7;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::SET3b()
{
    registers.b |= 0x08;
    registers.m = 2;
}
void CPU::SET3c()
{
    registers.b |= 0x08;
    registers.m = 2;
}
void CPU::SET3d()
{
    registers.b |= 0x08;
    registers.m = 2;
}
void CPU::SET3e()
{
    registers.b |= 0x08;
    registers.m = 2;
}
void CPU::SET3h()
{
    registers.b |= 0x08;
    registers.m = 2;
}
void CPU::SET3l()
{
    registers.b |= 0x08;
    registers.m = 2;
}
void CPU::SET3a()
{
    registers.b |= 0x08;
    registers.m = 2;
}
void CPU::SET3m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i |= 0x08;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::BIT4b()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.b & 0x10) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT4c()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.c & 0x10) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT4d()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.d & 0x10) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT4e()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.e & 0x10) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT4h()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.h & 0x10) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT4l()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.l & 0x10) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT4a()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.a & 0x10) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT4m()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (mmu->ReadByte((registers.h << 8) + registers.l) & 0x10) ? 0 : 0x80;
    registers.m = 3;
}

void CPU::RES4b()
{
    registers.b &= 0xEF;
    registers.m = 2;
}
void CPU::RES4c()
{
    registers.c &= 0xEF;
    registers.m = 2;
}
void CPU::RES4d()
{
    registers.d &= 0xEF;
    registers.m = 2;
}
void CPU::RES4e()
{
    registers.e &= 0xEF;
    registers.m = 2;
}
void CPU::RES4h()
{
    registers.h &= 0xEF;
    registers.m = 2;
}
void CPU::RES4l()
{
    registers.l &= 0xEF;
    registers.m = 2;
}
void CPU::RES4a()
{
    registers.a &= 0xEF;
    registers.m = 2;
}
void CPU::RES4m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i &= 0xEF;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::SET4b()
{
    registers.b |= 0x10;
    registers.m = 2;
}
void CPU::SET4c()
{
    registers.b |= 0x10;
    registers.m = 2;
}
void CPU::SET4d()
{
    registers.b |= 0x10;
    registers.m = 2;
}
void CPU::SET4e()
{
    registers.b |= 0x10;
    registers.m = 2;
}
void CPU::SET4h()
{
    registers.b |= 0x10;
    registers.m = 2;
}
void CPU::SET4l()
{
    registers.b |= 0x10;
    registers.m = 2;
}
void CPU::SET4a()
{
    registers.b |= 0x10;
    registers.m = 2;
}
void CPU::SET4m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i |= 0x10;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::BIT5b()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.b & 0x20) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT5c()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.c & 0x20) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT5d()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.d & 0x20) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT5e()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.e & 0x20) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT5h()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.h & 0x20) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT5l()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.l & 0x20) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT5a()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.a & 0x20) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT5m()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (mmu->ReadByte((registers.h << 8) + registers.l) & 0x20) ? 0 : 0x80;
    registers.m = 3;
}

void CPU::RES5b()
{
    registers.b &= 0xDF;
    registers.m = 2;
}
void CPU::RES5c()
{
    registers.c &= 0xDF;
    registers.m = 2;
}
void CPU::RES5d()
{
    registers.d &= 0xDF;
    registers.m = 2;
}
void CPU::RES5e()
{
    registers.e &= 0xDF;
    registers.m = 2;
}
void CPU::RES5h()
{
    registers.h &= 0xDF;
    registers.m = 2;
}
void CPU::RES5l()
{
    registers.l &= 0xDF;
    registers.m = 2;
}
void CPU::RES5a()
{
    registers.a &= 0xDF;
    registers.m = 2;
}
void CPU::RES5m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i &= 0xDF;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::SET5b()
{
    registers.b |= 0x20;
    registers.m = 2;
}
void CPU::SET5c()
{
    registers.b |= 0x20;
    registers.m = 2;
}
void CPU::SET5d()
{
    registers.b |= 0x20;
    registers.m = 2;
}
void CPU::SET5e()
{
    registers.b |= 0x20;
    registers.m = 2;
}
void CPU::SET5h()
{
    registers.b |= 0x20;
    registers.m = 2;
}
void CPU::SET5l()
{
    registers.b |= 0x20;
    registers.m = 2;
}
void CPU::SET5a()
{
    registers.b |= 0x20;
    registers.m = 2;
}
void CPU::SET5m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i |= 0x20;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::BIT6b()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.b & 0x40) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT6c()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.c & 0x40) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT6d()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.d & 0x40) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT6e()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.e & 0x40) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT6h()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.h & 0x40) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT6l()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.l & 0x40) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT6a()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.a & 0x40) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT6m()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (mmu->ReadByte((registers.h << 8) + registers.l) & 0x40) ? 0 : 0x80;
    registers.m = 3;
}

void CPU::RES6b()
{
    registers.b &= 0xBF;
    registers.m = 2;
}
void CPU::RES6c()
{
    registers.c &= 0xBF;
    registers.m = 2;
}
void CPU::RES6d()
{
    registers.d &= 0xBF;
    registers.m = 2;
}
void CPU::RES6e()
{
    registers.e &= 0xBF;
    registers.m = 2;
}
void CPU::RES6h()
{
    registers.h &= 0xBF;
    registers.m = 2;
}
void CPU::RES6l()
{
    registers.l &= 0xBF;
    registers.m = 2;
}
void CPU::RES6a()
{
    registers.a &= 0xBF;
    registers.m = 2;
}
void CPU::RES6m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i &= 0xBF;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::SET6b()
{
    registers.b |= 0x40;
    registers.m = 2;
}
void CPU::SET6c()
{
    registers.b |= 0x40;
    registers.m = 2;
}
void CPU::SET6d()
{
    registers.b |= 0x40;
    registers.m = 2;
}
void CPU::SET6e()
{
    registers.b |= 0x40;
    registers.m = 2;
}
void CPU::SET6h()
{
    registers.b |= 0x40;
    registers.m = 2;
}
void CPU::SET6l()
{
    registers.b |= 0x40;
    registers.m = 2;
}
void CPU::SET6a()
{
    registers.b |= 0x40;
    registers.m = 2;
}
void CPU::SET6m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i |= 0x40;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::BIT7b()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.b & 0x80) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT7c()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.c & 0x80) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT7d()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.d & 0x80) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT7e()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.e & 0x80) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT7h()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.h & 0x80) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT7l()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.l & 0x80) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT7a()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (registers.a & 0x80) ? 0 : 0x80;
    registers.m = 2;
}
void CPU::BIT7m()
{
    registers.f &= 0x1F;
    registers.f |= 0x20;
    registers.f = (mmu->ReadByte((registers.h << 8) + registers.l) & 0x80) ? 0 : 0x80;
    registers.m = 3;
}

void CPU::RES7b()
{
    registers.b &= 0x7F;
    registers.m = 2;
}
void CPU::RES7c()
{
    registers.c &= 0x7F;
    registers.m = 2;
}
void CPU::RES7d()
{
    registers.d &= 0x7F;
    registers.m = 2;
}
void CPU::RES7e()
{
    registers.e &= 0x7F;
    registers.m = 2;
}
void CPU::RES7h()
{
    registers.h &= 0x7F;
    registers.m = 2;
}
void CPU::RES7l()
{
    registers.l &= 0x7F;
    registers.m = 2;
}
void CPU::RES7a()
{
    registers.a &= 0x7F;
    registers.m = 2;
}
void CPU::RES7m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i &= 0x7F;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::SET7b()
{
    registers.b |= 0x80;
    registers.m = 2;
}
void CPU::SET7c()
{
    registers.b |= 0x80;
    registers.m = 2;
}
void CPU::SET7d()
{
    registers.b |= 0x80;
    registers.m = 2;
}
void CPU::SET7e()
{
    registers.b |= 0x80;
    registers.m = 2;
}
void CPU::SET7h()
{
    registers.b |= 0x80;
    registers.m = 2;
}
void CPU::SET7l()
{
    registers.b |= 0x80;
    registers.m = 2;
}
void CPU::SET7a()
{
    registers.b |= 0x80;
    registers.m = 2;
}
void CPU::SET7m()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    i |= 0x80;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.m = 4;
}

void CPU::RLA()
{
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = registers.a & 0x80 ? 0x10 : 0;
    registers.a = (registers.a << 1) + ci;
    registers.a &= 255;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 1;
}
void CPU::RLCA()
{
    auto ci = registers.a & 0x80 ? 1 : 0;
    auto co = registers.a & 0x80 ? 0x10 : 0;
    registers.a = (registers.a << 1) + ci;
    registers.a &= 255;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 1;
}
void CPU::RRA()
{
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = registers.a & 1 ? 0x10 : 0;
    registers.a = (registers.a >> 1) + ci;
    registers.a &= 255;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 1;
}
void CPU::RRCA()
{
    auto ci = registers.a & 1 ? 0x80 : 0;
    auto co = registers.a & 1 ? 0x10 : 0;
    registers.a = (registers.a >> 1) + ci;
    registers.a &= 255;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 1;
}

void CPU::RLr_b()
{
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = registers.b & 0x80 ? 0x10 : 0;
    registers.b = (registers.b << 1) + ci;
    registers.b &= 255;
    registers.f = (registers.b) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLr_c()
{
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = registers.c & 0x80 ? 0x10 : 0;
    registers.c = (registers.c << 1) + ci;
    registers.c &= 255;
    registers.f = (registers.c) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLr_d()
{
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = registers.d & 0x80 ? 0x10 : 0;
    registers.d = (registers.d << 1) + ci;
    registers.d &= 255;
    registers.f = (registers.d) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLr_e()
{
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = registers.e & 0x80 ? 0x10 : 0;
    registers.e = (registers.e << 1) + ci;
    registers.e &= 255;
    registers.f = (registers.e) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLr_h()
{
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = registers.h & 0x80 ? 0x10 : 0;
    registers.h = (registers.h << 1) + ci;
    registers.h &= 255;
    registers.f = (registers.h) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLr_l()
{
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = registers.l & 0x80 ? 0x10 : 0;
    registers.l = (registers.l << 1) + ci;
    registers.l &= 255;
    registers.f = (registers.l) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLr_a()
{
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = registers.a & 0x80 ? 0x10 : 0;
    registers.a = (registers.a << 1) + ci;
    registers.a &= 255;
    registers.f = (registers.a) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLHL()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    auto ci = registers.f & 0x10 ? 1 : 0;
    auto co = i & 0x80 ? 0x10 : 0;
    i = (i << 1) + ci;
    i &= 255;
    registers.f = (i) ? 0 : 0x80;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 4;
}

void CPU::RLCr_b()
{
    auto ci = registers.b & 0x80 ? 1 : 0;
    auto co = registers.b & 0x80 ? 0x10 : 0;
    registers.b = (registers.b << 1) + ci;
    registers.b &= 255;
    registers.f = (registers.b) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLCr_c()
{
    auto ci = registers.c & 0x80 ? 1 : 0;
    auto co = registers.c & 0x80 ? 0x10 : 0;
    registers.c = (registers.c << 1) + ci;
    registers.c &= 255;
    registers.f = (registers.c) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLCr_d()
{
    auto ci = registers.d & 0x80 ? 1 : 0;
    auto co = registers.d & 0x80 ? 0x10 : 0;
    registers.d = (registers.d << 1) + ci;
    registers.d &= 255;
    registers.f = (registers.d) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLCr_e()
{
    auto ci = registers.e & 0x80 ? 1 : 0;
    auto co = registers.e & 0x80 ? 0x10 : 0;
    registers.e = (registers.e << 1) + ci;
    registers.e &= 255;
    registers.f = (registers.e) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLCr_h()
{
    auto ci = registers.h & 0x80 ? 1 : 0;
    auto co = registers.h & 0x80 ? 0x10 : 0;
    registers.h = (registers.h << 1) + ci;
    registers.h &= 255;
    registers.f = (registers.h) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLCr_l()
{
    auto ci = registers.l & 0x80 ? 1 : 0;
    auto co = registers.l & 0x80 ? 0x10 : 0;
    registers.l = (registers.l << 1) + ci;
    registers.l &= 255;
    registers.f = (registers.l) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLCr_a()
{
    auto ci = registers.a & 0x80 ? 1 : 0;
    auto co = registers.a & 0x80 ? 0x10 : 0;
    registers.a = (registers.a << 1) + ci;
    registers.a &= 255;
    registers.f = (registers.a) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RLCHL()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    auto ci = i & 0x80 ? 1 : 0;
    auto co = i & 0x80 ? 0x10 : 0;
    i = (i << 1) + ci;
    i &= 255;
    registers.f = (i) ? 0 : 0x80;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 4;
}

void CPU::RRr_b()
{
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = registers.b & 1 ? 0x10 : 0;
    registers.b = (registers.b >> 1) + ci;
    registers.b &= 255;
    registers.f = (registers.b) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRr_c()
{
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = registers.c & 1 ? 0x10 : 0;
    registers.c = (registers.c >> 1) + ci;
    registers.c &= 255;
    registers.f = (registers.c) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRr_d()
{
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = registers.d & 1 ? 0x10 : 0;
    registers.d = (registers.d >> 1) + ci;
    registers.d &= 255;
    registers.f = (registers.d) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRr_e()
{
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = registers.e & 1 ? 0x10 : 0;
    registers.e = (registers.e >> 1) + ci;
    registers.e &= 255;
    registers.f = (registers.e) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRr_h()
{
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = registers.h & 1 ? 0x10 : 0;
    registers.h = (registers.h >> 1) + ci;
    registers.h &= 255;
    registers.f = (registers.h) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRr_l()
{
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = registers.l & 1 ? 0x10 : 0;
    registers.l = (registers.l >> 1) + ci;
    registers.l &= 255;
    registers.f = (registers.l) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRr_a()
{
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = registers.a & 1 ? 0x10 : 0;
    registers.a = (registers.a >> 1) + ci;
    registers.a &= 255;
    registers.f = (registers.a) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRHL()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    auto ci = registers.f & 0x10 ? 0x80 : 0;
    auto co = i & 1 ? 0x10 : 0;
    i = (i >> 1) + ci;
    i &= 255;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.f = (i) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 4;
}

void CPU::RRCr_b()
{
    auto ci = registers.b & 1 ? 0x80 : 0;
    auto co = registers.b & 1 ? 0x10 : 0;
    registers.b = (registers.b >> 1) + ci;
    registers.b &= 255;
    registers.f = (registers.b) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRCr_c()
{
    auto ci = registers.c & 1 ? 0x80 : 0;
    auto co = registers.c & 1 ? 0x10 : 0;
    registers.c = (registers.c >> 1) + ci;
    registers.c &= 255;
    registers.f = (registers.c) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRCr_d()
{
    auto ci = registers.d & 1 ? 0x80 : 0;
    auto co = registers.d & 1 ? 0x10 : 0;
    registers.d = (registers.d >> 1) + ci;
    registers.d &= 255;
    registers.f = (registers.d) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRCr_e()
{
    auto ci = registers.e & 1 ? 0x80 : 0;
    auto co = registers.e & 1 ? 0x10 : 0;
    registers.e = (registers.e >> 1) + ci;
    registers.e &= 255;
    registers.f = (registers.e) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRCr_h()
{
    auto ci = registers.h & 1 ? 0x80 : 0;
    auto co = registers.h & 1 ? 0x10 : 0;
    registers.h = (registers.h >> 1) + ci;
    registers.h &= 255;
    registers.f = (registers.h) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRCr_l()
{
    auto ci = registers.l & 1 ? 0x80 : 0;
    auto co = registers.l & 1 ? 0x10 : 0;
    registers.l = (registers.l >> 1) + ci;
    registers.l &= 255;
    registers.f = (registers.l) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRCr_a()
{
    auto ci = registers.a & 1 ? 0x80 : 0;
    auto co = registers.a & 1 ? 0x10 : 0;
    registers.a = (registers.a >> 1) + ci;
    registers.a &= 255;
    registers.f = (registers.a) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::RRCHL()
{
    auto i = mmu->ReadByte((registers.h << 8) + registers.l);
    auto ci = i & 1 ? 0x80 : 0;
    auto co = i & 1 ? 0x10 : 0;
    i = (i >> 1) + ci;
    i &= 255;
    mmu->WriteByte((registers.h << 8) + registers.l, i);
    registers.f = (i) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 4;
}

void CPU::SLAr_b()
{
    auto co = registers.b & 0x80 ? 0x10 : 0;
    registers.b = (registers.b << 1) & 255;
    registers.f = (registers.b) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLAr_c()
{
    auto co = registers.c & 0x80 ? 0x10 : 0;
    registers.c = (registers.c << 1) & 255;
    registers.f = (registers.c) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLAr_d()
{
    auto co = registers.d & 0x80 ? 0x10 : 0;
    registers.d = (registers.d << 1) & 255;
    registers.f = (registers.d) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLAr_e()
{
    auto co = registers.e & 0x80 ? 0x10 : 0;
    registers.e = (registers.e << 1) & 255;
    registers.f = (registers.e) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLAr_h()
{
    auto co = registers.h & 0x80 ? 0x10 : 0;
    registers.h = (registers.h << 1) & 255;
    registers.f = (registers.h) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLAr_l()
{
    auto co = registers.l & 0x80 ? 0x10 : 0;
    registers.l = (registers.l << 1) & 255;
    registers.f = (registers.l) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLAr_a()
{
    auto co = registers.a & 0x80 ? 0x10 : 0;
    registers.a = (registers.a << 1) & 255;
    registers.f = (registers.a) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}

void CPU::SLLr_b()
{
    auto co = registers.b & 0x80 ? 0x10 : 0;
    registers.b = (registers.b << 1) & 255 + 1;
    registers.f = (registers.b) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLLr_c()
{
    auto co = registers.c & 0x80 ? 0x10 : 0;
    registers.c = (registers.c << 1) & 255 + 1;
    registers.f = (registers.c) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLLr_d()
{
    auto co = registers.d & 0x80 ? 0x10 : 0;
    registers.d = (registers.d << 1) & 255 + 1;
    registers.f = (registers.d) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLLr_e()
{
    auto co = registers.e & 0x80 ? 0x10 : 0;
    registers.e = (registers.e << 1) & 255 + 1;
    registers.f = (registers.e) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLLr_h()
{
    auto co = registers.h & 0x80 ? 0x10 : 0;
    registers.h = (registers.h << 1) & 255 + 1;
    registers.f = (registers.h) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLLr_l()
{
    auto co = registers.l & 0x80 ? 0x10 : 0;
    registers.l = (registers.l << 1) & 255 + 1;
    registers.f = (registers.l) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SLLr_a()
{
    auto co = registers.a & 0x80 ? 0x10 : 0;
    registers.a = (registers.a << 1) & 255 + 1;
    registers.f = (registers.a) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}

void CPU::SRAr_b()
{
    auto ci = registers.b & 0x80;
    auto co = registers.b & 1 ? 0x10 : 0;
    registers.b = ((registers.b >> 1) + ci) & 255;
    registers.f = (registers.b) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRAr_c()
{
    auto ci = registers.c & 0x80;
    auto co = registers.c & 1 ? 0x10 : 0;
    registers.c = ((registers.c >> 1) + ci) & 255;
    registers.f = (registers.c) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRAr_d()
{
    auto ci = registers.d & 0x80;
    auto co = registers.d & 1 ? 0x10 : 0;
    registers.d = ((registers.d >> 1) + ci) & 255;
    registers.f = (registers.d) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRAr_e()
{
    auto ci = registers.e & 0x80;
    auto co = registers.e & 1 ? 0x10 : 0;
    registers.e = ((registers.e >> 1) + ci) & 255;
    registers.f = (registers.e) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRAr_h()
{
    auto ci = registers.h & 0x80;
    auto co = registers.h & 1 ? 0x10 : 0;
    registers.h = ((registers.h >> 1) + ci) & 255;
    registers.f = (registers.h) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRAr_l()
{
    auto ci = registers.l & 0x80;
    auto co = registers.l & 1 ? 0x10 : 0;
    registers.l = ((registers.l >> 1) + ci) & 255;
    registers.f = (registers.l) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRAr_a()
{
    auto ci = registers.a & 0x80;
    auto co = registers.a & 1 ? 0x10 : 0;
    registers.a = ((registers.a >> 1) + ci) & 255;
    registers.f = (registers.a) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}

void CPU::SRLr_b()
{
    auto co = registers.b & 1 ? 0x10 : 0;
    registers.b = (registers.b >> 1) & 255;
    registers.f = (registers.b) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRLr_c()
{
    auto co = registers.c & 1 ? 0x10 : 0;
    registers.c = (registers.c >> 1) & 255;
    registers.f = (registers.c) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRLr_d()
{
    auto co = registers.d & 1 ? 0x10 : 0;
    registers.d = (registers.d >> 1) & 255;
    registers.f = (registers.d) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRLr_e()
{
    auto co = registers.e & 1 ? 0x10 : 0;
    registers.e = (registers.e >> 1) & 255;
    registers.f = (registers.e) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRLr_h()
{
    auto co = registers.h & 1 ? 0x10 : 0;
    registers.h = (registers.h >> 1) & 255;
    registers.f = (registers.h) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRLr_l()
{
    auto co = registers.l & 1 ? 0x10 : 0;
    registers.l = (registers.l >> 1) & 255;
    registers.f = (registers.l) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}
void CPU::SRLr_a()
{
    auto co = registers.a & 1 ? 0x10 : 0;
    registers.a = (registers.a >> 1) & 255;
    registers.f = (registers.a) ? 0 : 0x80;
    registers.f = (registers.f & 0xEF) + co;
    registers.m = 2;
}

void CPU::CPL()
{
    registers.a ^= 255;
    registers.f = registers.a ? 0 : 0x80;
    registers.m = 1;
}
void CPU::NEG()
{
    registers.f = (registers.a == 0) ? 0 : 0x10;
    registers.a = 0 - registers.a;
    registers.a &= 255;
    if (!registers.a)
        registers.f |= 0x80;
    registers.m = 2;
}

void CPU::CCF()
{
    auto ci = registers.f & 0x10 ? 0 : 0x10;
    registers.f = (registers.f & 0xEF) + ci;
    registers.m = 1;
}
void CPU::SCF()
{
    registers.f |= 0x10;
    registers.m = 1;
}

/*--- Stack ---*/
void CPU::PUSHBC()
{
    registers.sp--;
    mmu->WriteByte(registers.sp, registers.b);
    registers.sp--;
    mmu->WriteByte(registers.sp, registers.c);
    registers.m = 3;
}
void CPU::PUSHDE()
{
    registers.sp--;
    mmu->WriteByte(registers.sp, registers.d);
    registers.sp--;
    mmu->WriteByte(registers.sp, registers.e);
    registers.m = 3;
}
void CPU::PUSHHL()
{
    registers.sp--;
    mmu->WriteByte(registers.sp, registers.h);
    registers.sp--;
    mmu->WriteByte(registers.sp, registers.l);
    registers.m = 3;
}
void CPU::PUSHAF()
{
    registers.sp--;
    mmu->WriteByte(registers.sp, registers.a);
    registers.sp--;
    mmu->WriteByte(registers.sp, registers.f);
    registers.m = 3;
}

void CPU::POPBC()
{
    registers.c = mmu->ReadByte(registers.sp);
    registers.sp++;
    registers.b = mmu->ReadByte(registers.sp);
    registers.sp++;
    registers.m = 3;
}
void CPU::POPDE()
{
    registers.e = mmu->ReadByte(registers.sp);
    registers.sp++;
    registers.d = mmu->ReadByte(registers.sp);
    registers.sp++;
    registers.m = 3;
}
void CPU::POPHL()
{
    registers.l = mmu->ReadByte(registers.sp);
    registers.sp++;
    registers.h = mmu->ReadByte(registers.sp);
    registers.sp++;
    registers.m = 3;
}
void CPU::POPAF()
{
    registers.f = mmu->ReadByte(registers.sp);
    registers.sp++;
    registers.a = mmu->ReadByte(registers.sp);
    registers.sp++;
    registers.m = 3;
}

/*--- Jump ---*/
void CPU::JPnn()
{
    registers.pc = mmu->ReadWord(registers.pc);
    registers.m = 3;
}
void CPU::JPHL()
{
    registers.pc = (registers.h << 8) + registers.l;
    registers.m = 1;
}
void CPU::JPNZnn()
{
    registers.m = 3;
    if ((registers.f & 0x80) == 0x00)
    {
        registers.pc = mmu->ReadWord(registers.pc);
        registers.m++;
    }
    else
        registers.pc += 2;
}
void CPU::JPZnn()
{
    registers.m = 3;
    if ((registers.f & 0x80) == 0x80)
    {
        registers.pc = mmu->ReadWord(registers.pc);
        registers.m++;
    }
    else
        registers.pc += 2;
}
void CPU::JPNCnn()
{
    registers.m = 3;
    if ((registers.f & 0x10) == 0x00)
    {
        registers.pc = mmu->ReadWord(registers.pc);
        registers.m++;
    }
    else
        registers.pc += 2;
}
void CPU::JPCnn()
{
    registers.m = 3;
    if ((registers.f & 0x10) == 0x10)
    {
        registers.pc = mmu->ReadWord(registers.pc);
        registers.m++;
    }
    else
        registers.pc += 2;
}

void CPU::JRn()
{
    int8_t i = mmu->ReadByte(registers.pc);
    if (i > 127)
        i = -((~i + 1) & 255);
    registers.pc++;
    registers.m = 2;
    registers.pc += i;
    registers.m++;
}
void CPU::JRNZn()
{
    int8_t i = mmu->ReadByte(registers.pc);
    if (i > 127)
        i = -((~i + 1) & 255);
    registers.pc++;
    registers.m = 2;
    if ((registers.f & 0x80) == 0x00)
    {
        registers.pc += i;
        registers.m++;
    }
}
void CPU::JRZn()
{
    int8_t i = mmu->ReadByte(registers.pc);
    if (i > 127)
        i = -((~i + 1) & 255);
    registers.pc++;
    registers.m = 2;
    if ((registers.f & 0x80) == 0x80)
    {
        registers.pc += i;
        registers.m++;
    }
}
void CPU::JRNCn()
{
    int8_t i = mmu->ReadByte(registers.pc);
    if (i > 127)
        i = -((~i + 1) & 255);
    registers.pc++;
    registers.m = 2;
    if ((registers.f & 0x10) == 0x00)
    {
        registers.pc += i;
        registers.m++;
    }
}
void CPU::JRCn()
{
    int8_t i = mmu->ReadByte(registers.pc);
    if (i > 127)
        i = -((~i + 1) & 255);
    registers.pc++;
    registers.m = 2;
    if ((registers.f & 0x10) == 0x10)
    {
        registers.pc += i;
        registers.m++;
    }
}

void CPU::DJNZn()
{
    int8_t i = mmu->ReadByte(registers.pc);
    if (i > 127)
        i = -((~i + 1) & 255);
    registers.pc++;
    registers.m = 2;
    registers.b--;
    if (registers.b)
    {
        registers.pc += i;
        registers.m++;
    }
}

void CPU::CALLnn()
{
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc + 2);
    registers.pc = mmu->ReadWord(registers.pc);
    registers.m = 5;
}
void CPU::CALLNZnn()
{
    registers.m = 3;
    if ((registers.f & 0x80) == 0x00)
    {
        registers.sp -= 2;
        mmu->WriteWord(registers.sp, registers.pc + 2);
        registers.pc = mmu->ReadWord(registers.pc);
        registers.m += 2;
    }
    else
        registers.pc += 2;
}
void CPU::CALLZnn()
{
    registers.m = 3;
    if ((registers.f & 0x80) == 0x80)
    {
        registers.sp -= 2;
        mmu->WriteWord(registers.sp, registers.pc + 2);
        registers.pc = mmu->ReadWord(registers.pc);
        registers.m += 2;
    }
    else
        registers.pc += 2;
}
void CPU::CALLNCnn()
{
    registers.m = 3;
    if ((registers.f & 0x10) == 0x00)
    {
        registers.sp -= 2;
        mmu->WriteWord(registers.sp, registers.pc + 2);
        registers.pc = mmu->ReadWord(registers.pc);
        registers.m += 2;
    }
    else
        registers.pc += 2;
}
void CPU::CALLCnn()
{
    registers.m = 3;
    if ((registers.f & 0x10) == 0x10)
    {
        registers.sp -= 2;
        mmu->WriteWord(registers.sp, registers.pc + 2);
        registers.pc = mmu->ReadWord(registers.pc);
        registers.m += 2;
    }
    else
        registers.pc += 2;
}

void CPU::RET()
{
    registers.pc = mmu->ReadWord(registers.sp);
    registers.sp += 2;
    registers.m = 3;
}
void CPU::RETI()
{
    registers.ime = 1;
    RRS();
    registers.pc = mmu->ReadWord(registers.sp);
    registers.sp += 2;
    registers.m = 3;
}
void CPU::RETNZ()
{
    registers.m = 1;
    if ((registers.f & 0x80) == 0x00)
    {
        registers.pc = mmu->ReadWord(registers.sp);
        registers.sp += 2;
        registers.m += 2;
    }
}
void CPU::RETZ()
{
    registers.m = 1;
    if ((registers.f & 0x80) == 0x80)
    {
        registers.pc = mmu->ReadWord(registers.sp);
        registers.sp += 2;
        registers.m += 2;
    }
}
void CPU::RETNC()
{
    registers.m = 1;
    if ((registers.f & 0x10) == 0x00)
    {
        registers.pc = mmu->ReadWord(registers.sp);
        registers.sp += 2;
        registers.m += 2;
    }
}
void CPU::RETC()
{
    registers.m = 1;
    if ((registers.f & 0x10) == 0x10)
    {
        registers.pc = mmu->ReadWord(registers.sp);
        registers.sp += 2;
        registers.m += 2;
    }
}

void CPU::RST00()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x00;
    registers.m = 3;
}
void CPU::RST08()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x08;
    registers.m = 3;
}
void CPU::RST10()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x10;
    registers.m = 3;
}
void CPU::RST18()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x18;
    registers.m = 3;
}
void CPU::RST20()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x20;
    registers.m = 3;
}
void CPU::RST28()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x28;
    registers.m = 3;
}
void CPU::RST30()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x30;
    registers.m = 3;
}
void CPU::RST38()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x38;
    registers.m = 3;
}
void CPU::RST40()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x40;
    registers.m = 3;
}
void CPU::RST48()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x48;
    registers.m = 3;
}
void CPU::RST50()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x50;
    registers.m = 3;
}
void CPU::RST58()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x58;
    registers.m = 3;
}
void CPU::RST60()
{
    RSV();
    registers.sp -= 2;
    mmu->WriteWord(registers.sp, registers.pc);
    registers.pc = 0x60;
    registers.m = 3;
}

void CPU::NOP() { registers.m = 1; }
void CPU::HALT()
{
    halt = true;
    registers.m = 1;
}

void CPU::DI()
{
    registers.ime = 0;
    registers.m = 1;
}
void CPU::EI()
{
    registers.ime = 1;
    registers.m = 1;
}

void CPU::LDmmSP() {}

// helper functions
void CPU::RSV()
{
    temp_registers.a = registers.a;
    temp_registers.b = registers.b;
    temp_registers.c = registers.c;
    temp_registers.d = registers.d;
    temp_registers.e = registers.e;
    temp_registers.f = registers.f;
    temp_registers.h = registers.h;
    temp_registers.l = registers.l;
}

void CPU::RRS()
{
    registers.a = temp_registers.a;
    registers.b = temp_registers.b;
    registers.c = temp_registers.c;
    registers.d = temp_registers.d;
    registers.e = temp_registers.e;
    registers.f = temp_registers.f;
    registers.h = temp_registers.h;
    registers.l = temp_registers.l;
}

void CPU::MAPcb()
{
    auto op_code = mmu->ReadByte(registers.pc);
    registers.pc++;
    ExecuteCBInstruction(op_code);
}

void CPU::XX()
{
    // undefined map entry
    auto op_code = registers.pc - 1;
    //std::cout << "OpCode: '" << ToHexString(op_code) << "'" << std::endl;
    stop = true;
}