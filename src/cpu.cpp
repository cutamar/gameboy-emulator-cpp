#include <stdexcept>
#include <iostream>
#include "cpu.h"
#include "mmu.h"

CPU::CPU() : stop{false}, halt{false} {}

void CPU::ExecuteInstruction(uint16_t op_code) {
    switch (op_code) {
        case 0x0000:
            NOP();
            break;
        case 0x0001:
            LDBCnn();
            break;
        case 0x0002:
            LDBCmA();
            break;
        case 0x0003:
            INCBC();
            break;
        case 0x0004:
            INCr_b();
            break;
        case 0x0005:
            DECr_b();
            break;
        case 0x0006:
            LDrn_b();
            break;
        case 0x0007:
            RLCA();
            break;
        case 0x0008:
            LDmmSP();
            break;
        case 0x0009:
            ADDHLBC();
            break;
        case 0x000A:
            LDABCm();
            break;
        case 0x000B:
            DECBC();
            break;
        case 0x000C:
            INCr_c();
            break;
        case 0x000D:
            DECr_c();
            break;
        case 0x000E:
            LDrn_c();
            break;
        case 0x000F:
            RRCA();
            break;
        case 0x0010:
            DJNZn();
            break;
        case 0x0011:
            LDDEnn();
            break;
        case 0x0012:
            LDDEmA();
            break;
        case 0x0013:
            INCDE();
            break;
        case 0x0014:
            INCr_d();
            break;
        case 0x0015:
            DECr_d();
            break;
        case 0x0016:
            LDrn_d();
            break;
        case 0x0017:
            RLA();
            break;
        case 0x0018:
            JRn();
            break;
        case 0x0019:
            ADDHLDE();
            break;
        case 0x001A:
            LDADEm();
            break;
        case 0x001B:
            DECDE();
            break;
        case 0x001C:
            INCr_e();
            break;
        case 0x001D:
            DECr_e();
            break;
        case 0x001E:
            LDrn_e();
            break;
        case 0x001F:
            RRA();
            break;
        case 0x0020:
            JRNZn();
            break;
        case 0x0021:
            LDHLnn();
            break;
        case 0x0022:
            LDHLIA();
            break;
        case 0x0023:
            INCHL();
            break;
        case 0x0024:
            INCr_h();
            break;
        case 0x0025:
            DECr_h();
            break;
        case 0x0026:
            LDrn_h();
            break;
        case 0x0027:
            DAA();
            break;
        case 0x0028:
            JRZn();
            break;
        case 0x0029:
            ADDHLHL();
            break;
        case 0x002A:
            LDAHLI();
            break;
        case 0x002B:
            DECHL();
            break;
        case 0x002C:
            INCr_l();
            break;
        case 0x002D:
            DECr_l();
            break;
        case 0x002E:
            LDrn_l();
            break;
        case 0x002F:
            CPL();
            break;
        case 0x0030:
            JRNCn();
            break;
        case 0x0031:
            LDSPnn();
            break;
        case 0x0032:
            LDHLDA();
            break;
        case 0x0033:
            INCSP();
            break;
        case 0x0034:
            INCHLm();
            break;
        case 0x0035:
            DECHLm();
            break;
        case 0x0036:
            LDHLmn();
            break;
        case 0x0037:
            SCF();
            break;
        case 0x0038:
            JRCn();
            break;
        case 0x0039:
            ADDHLSP();
            break;
        case 0x003A:
            LDAHLD();
            break;
        case 0x003B:
            DECSP();
            break;
        case 0x003C:
            INCr_a();
            break;
        case 0x003D:
            DECr_a();
            break;
        case 0x003E:
            LDrn_a();
            break;
        case 0x003F:
            CCF();
            break;
        case 0x0040:
            LDrr_bb();
            break;
        case 0x0041:
            LDrr_bc();
            break;
        case 0x0042:
            LDrr_bd();
            break;
        case 0x0043:
            LDrr_be();
            break;
        case 0x0044:
            LDrr_bh();
            break;
        case 0x0045:
            LDrr_bl();
            break;
        case 0x0046:
            LDrHLm_b();
            break;
        case 0x0047:
            LDrr_ba();
            break;
        case 0x0048:
            LDrr_cb();
            break;
        case 0x0049:
            LDrr_cc();
            break;
        case 0x004A:
            LDrr_cd();
            break;
        case 0x004B:
            LDrr_ce();
            break;
        case 0x004C:
            LDrr_ch();
            break;
        case 0x004D:
            LDrr_cl();
            break;
        case 0x004E:
            LDrHLm_c();
            break;
        case 0x004F:
            LDrr_ca();
            break;
        case 0x0050:
            LDrr_db();
            break;
        case 0x0051:
            LDrr_dc();
            break;
        case 0x0052:
            LDrr_dd();
            break;
        case 0x0053:
            LDrr_de();
            break;
        case 0x0054:
            LDrr_dh();
            break;
        case 0x0055:
            LDrr_dl();
            break;
        case 0x0056:
            LDrHLm_d();
            break;
        case 0x0057:
            LDrr_da();
            break;
        case 0x0058:
            LDrr_eb();
            break;
        case 0x0059:
            LDrr_ec();
            break;
        case 0x005A:
            LDrr_ed();
            break;
        case 0x005B:
            LDrr_ee();
            break;
        case 0x005C:
            LDrr_eh();
            break;
        case 0x005D:
            LDrr_el();
            break;
        case 0x005E:
            LDrHLm_e();
            break;
        case 0x005F:
            LDrr_ea();
            break;
        case 0x0060:
            LDrr_hb();
            break;
        case 0x0061:
            LDrr_hc();
            break;
        case 0x0062:
            LDrr_hd();
            break;
        case 0x0063:
            LDrr_he();
            break;
        case 0x0064:
            LDrr_hh();
            break;
        case 0x0065:
            LDrr_hl();
            break;
        case 0x0066:
            LDrHLm_h();
            break;
        case 0x0067:
            LDrr_ha();
            break;
        case 0x0068:
            LDrr_lb();
            break;
        case 0x0069:
            LDrr_lc();
            break;
        case 0x006A:
            LDrr_ld();
            break;
        case 0x006B:
            LDrr_le();
            break;
        case 0x006C:
            LDrr_lh();
            break;
        case 0x006D:
            LDrr_ll();
            break;
        case 0x006E:
            LDrHLm_l();
            break;
        case 0x006F:
            LDrr_la();
            break;
        case 0x0070:
            LDHLmr_b();
            break;
        case 0x0071:
            LDHLmr_c();
            break;
        case 0x0072:
            LDHLmr_d();
            break;
        case 0x0073:
            LDHLmr_e();
            break;
        case 0x0074:
            LDHLmr_h();
            break;
        case 0x0075:
            LDHLmr_l();
            break;
        case 0x0076:
            HALT();
            break;
        case 0x0077:
            LDHLmr_a();
            break;
        case 0x0078:
            LDrr_ab();
            break;
        case 0x0079:
            LDrr_ac();
            break;
        case 0x007A:
            LDrr_ad();
            break;
        case 0x007B:
            LDrr_ae();
            break;
        case 0x007C:
            LDrr_ah();
            break;
        case 0x007D:
            LDrr_al();
            break;
        case 0x007E:
            LDrHLm_a();
            break;
        case 0x007F:
            LDrr_aa();
            break;
        case 0x0080:
            ADDr_b();
            break;
        case 0x0081:
            ADDr_c();
            break;
        case 0x0082:
            ADDr_d();
            break;
        case 0x0083:
            ADDr_e();
            break;
        case 0x0084:
            ADDr_h();
            break;
        case 0x0085:
            ADDr_l();
            break;
        case 0x0086:
            ADDHL();
            break;
        case 0x0087:
            ADDr_a();
            break;
        case 0x0088:
            ADCr_b();
            break;
        case 0x0089:
            ADCr_c();
            break;
        case 0x008A:
            ADCr_d();
            break;
        case 0x008B:
            ADCr_e();
            break;
        case 0x008C:
            ADCr_h();
            break;
        case 0x008D:
            ADCr_l();
            break;
        case 0x008E:
            ADCHL();
            break;
        case 0x008F:
            ADCr_a();
            break;
        case 0x0090:
            SUBr_b();
            break;
        case 0x0091:
            SUBr_c();
            break;
        case 0x0092:
            SUBr_d();
            break;
        case 0x0093:
            SUBr_e();
            break;
        case 0x0094:
            SUBr_h();
            break;
        case 0x0095:
            SUBr_l();
            break;
        case 0x0096:
            SUBHL();
            break;
        case 0x0097:
            SUBr_a();
            break;
        case 0x0098:
            SBCr_b();
            break;
        case 0x0099:
            SBCr_c();
            break;
        case 0x009A:
            SBCr_d();
            break;
        case 0x009B:
            SBCr_e();
            break;
        case 0x009C:
            SBCr_h();
            break;
        case 0x009D:
            SBCr_l();
            break;
        case 0x009E:
            SBCHL();
            break;
        case 0x009F:
            SBCr_a();
            break;
        case 0x00A0:
            ANDr_b();
            break;
        case 0x00A1:
            ANDr_c();
            break;
        case 0x00A2:
            ANDr_d();
            break;
        case 0x00A3:
            ANDr_e();
            break;
        case 0x00A4:
            ANDr_h();
            break;
        case 0x00A5:
            ANDr_l();
            break;
        case 0x00A6:
            ANDHL();
            break;
        case 0x00A7:
            ANDr_a();
            break;
        case 0x00A8:
            XORr_b();
            break;
        case 0x00A9:
            XORr_c();
            break;
        case 0x00AA:
            XORr_d();
            break;
        case 0x00AB:
            XORr_e();
            break;
        case 0x00AC:
            XORr_h();
            break;
        case 0x00AD:
            XORr_l();
            break;
        case 0x00AE:
            XORHL();
            break;
        case 0x00AF:
            XORr_a();
            break;
        case 0x00B0:
            ORr_b();
            break;
        case 0x00B1:
            ORr_c();
            break;
        case 0x00B2:
            ORr_d();
            break;
        case 0x00B3:
            ORr_e();
            break;
        case 0x00B4:
            ORr_h();
            break;
        case 0x00B5:
            ORr_l();
            break;
        case 0x00B6:
            ORHL();
            break;
        case 0x00B7:
            ORr_a();
            break;
        case 0x00B8:
            CPr_b();
            break;
        case 0x00B9:
            CPr_c();
            break;
        case 0x00BA:
            CPr_d();
            break;
        case 0x00BB:
            CPr_e();
            break;
        case 0x00BC:
            CPr_h();
            break;
        case 0x00BD:
            CPr_l();
            break;
        case 0x00BE:
            CPHL();
            break;
        case 0x00BF:
            CPr_a();
            break;
        case 0x00C0:
            RETNZ();
            break;
        case 0x00C1:
            POPBC();
            break;
        case 0x00C2:
            JPNZnn();
            break;
        case 0x00C3:
            JPnn();
            break;
        case 0x00C4:
            CALLNZnn();
            break;
        case 0x00C5:
            PUSHBC();
            break;
        case 0x00C6:
            ADDn();
            break;
        case 0x00C7:
            RST00();
            break;
        case 0x00C8:
            RETZ();
            break;
        case 0x00C9:
            RET();
            break;
        case 0x00CA:
            JPZnn();
            break;
        case 0x00CB:
            MAPcb();
            break;
        case 0x00CC:
            CALLZnn();
            break;
        case 0x00CD:
            CALLnn();
            break;
        case 0x00CE:
            ADCn();
            break;
        case 0x00CF:
            RST08();
            break;
        case 0x00D0:
            RETNC();
            break;
        case 0x00D1:
            POPDE();
            break;
        case 0x00D2:
            JPNCnn();
            break;
        case 0x00D3:
            XX();
            break;
        case 0x00D4:
            CALLNCnn();
            break;
        case 0x00D5:
            PUSHDE();
            break;
        case 0x00D6:
            SUBn();
            break;
        case 0x00D7:
            RST10();
            break;
        case 0x00D8:
            RETC();
            break;
        case 0x00D9:
            RETI();
            break;
        case 0x00DA:
            JPCnn();
            break;
        case 0x00DB:
            XX();
            break;
        case 0x00DC:
            CALLCnn();
            break;
        case 0x00DD:
            XX();
            break;
        case 0x00DE:
            SBCn();
            break;
        case 0x00DF:
            RST18();
            break;
        case 0x00E0:
            LDIOnA();
            break;
        case 0x00E1:
            POPHL();
            break;
        case 0x00E2:
            LDIOCA();
            break;
        case 0x00E3:
            XX();
            break;
        case 0x00E4:
            XX();
            break;
        case 0x00E5:
            PUSHHL();
            break;
        case 0x00E6:
            ANDn();
            break;
        case 0x00E7:
            RST20();
            break;
        case 0x00E8:
            ADDSPn();
            break;
        case 0x00E9:
            JPHL();
            break;
        case 0x00EA:
            LDmmA();
            break;
        case 0x00EB:
            XX();
            break;
        case 0x00EC:
            XX();
            break;
        case 0x00ED:
            XX();
            break;
        case 0x00EE:
            XORn();
            break;
        case 0x00EF:
            RST28();
            break;
        case 0x00F0:
            LDAIOn();
            break;
        case 0x00F1:
            POPAF();
            break;
        case 0x00F2:
            LDAIOC();
            break;
        case 0x00F3:
            DI();
            break;
        case 0x00F4:
            XX();
            break;
        case 0x00F5:
            PUSHAF();
            break;
        case 0x00F6:
            ORn();
            break;
        case 0x00F7:
            RST30();
            break;
        case 0x00F8:
            LDHLSPn();
            break;
        case 0x00F9:
            XX();
            break;
        case 0x00FA:
            LDAmm();
            break;
        case 0x00FB:
            EI();
            break;
        case 0x00FC:
            XX();
            break;
        case 0x00FD:
            XX();
            break;
        case 0x00FE:
            CPn();
            break;
        case 0x00FF:
            RST38();
            break;
        default:
            throw std::runtime_error("OpCode: '" + ToHexString(op_code) + "'\n");
    }
    UpdateClock();
}

void CPU::ExecuteCBInstruction(uint16_t op_code) {
    switch (op_code) {
        case 0xCB00:
            RLCr_b();
            break;
        case 0xCB01:
            RLCr_c();
            break;
        case 0xCB02:
            RLCr_d();
            break;
        case 0xCB03:
            RLCr_e();
            break;
        case 0xCB04:
            RLCr_h();
            break;
        case 0xCB05:
            RLCr_l();
            break;
        case 0xCB06:
            RLCHL();
            break;
        case 0xCB07:
            RLCr_a();
            break;
        case 0xCB08:
            RRCr_b();
            break;
        case 0xCB09:
            RRCr_c();
            break;
        case 0xCB0A:
            RRCr_d();
            break;
        case 0xCB0B:
            RRCr_e();
            break;
        case 0xCB0C:
            RRCr_h();
            break;
        case 0xCB0D:
            RRCr_l();
            break;
        case 0xCB0E:
            RRCHL();
            break;
        case 0xCB0F:
            RRCr_a();
            break;
        case 0xCB10:
            RLr_b();
            break;
        case 0xCB11:
            RLr_c();
            break;
        case 0xCB12:
            RLr_d();
            break;
        case 0xCB13:
            RLr_e();
            break;
        case 0xCB14:
            RLr_h();
            break;
        case 0xCB15:
            RLr_l();
            break;
        case 0xCB16:
            RLHL();
            break;
        case 0xCB17:
            RLr_a();
            break;
        case 0xCB18:
            RRr_b();
            break;
        case 0xCB19:
            RRr_c();
            break;
        case 0xCB1A:
            RRr_d();
            break;
        case 0xCB1B:
            RRr_e();
            break;
        case 0xCB1C:
            RRr_h();
            break;
        case 0xCB1D:
            RRr_l();
            break;
        case 0xCB1E:
            RRHL();
            break;
        case 0xCB1F:
            RRr_a();
            break;
        case 0xCB20:
            SLAr_b();
            break;
        case 0xCB21:
            SLAr_c();
            break;
        case 0xCB22:
            SLAr_d();
            break;
        case 0xCB23:
            SLAr_e();
            break;
        case 0xCB24:
            SLAr_h();
            break;
        case 0xCB25:
            SLAr_l();
            break;
        case 0xCB26:
            XX();
            break;
        case 0xCB27:
            SLAr_a();
            break;
        case 0xCB28:
            SRAr_b();
            break;
        case 0xCB29:
            SRAr_c();
            break;
        case 0xCB2A:
            SRAr_d();
            break;
        case 0xCB2B:
            SRAr_e();
            break;
        case 0xCB2C:
            SRAr_h();
            break;
        case 0xCB2D:
            SRAr_l();
            break;
        case 0xCB2E:
            XX();
            break;
        case 0xCB2F:
            SRAr_a();
            break;
        case 0xCB30:
            SWAPr_b();
            break;
        case 0xCB31:
            SWAPr_c();
            break;
        case 0xCB32:
            SWAPr_d();
            break;
        case 0xCB33:
            SWAPr_e();
            break;
        case 0xCB34:
            SWAPr_h();
            break;
        case 0xCB35:
            SWAPr_l();
            break;
        case 0xCB36:
            XX();
            break;
        case 0xCB37:
            SWAPr_a();
            break;
        case 0xCB38:
            SRLr_b();
            break;
        case 0xCB39:
            SRLr_c();
            break;
        case 0xCB3A:
            SRLr_d();
            break;
        case 0xCB3B:
            SRLr_e();
            break;
        case 0xCB3C:
            SRLr_h();
            break;
        case 0xCB3D:
            SRLr_l();
            break;
        case 0xCB3E:
            XX();
            break;
        case 0xCB3F:
            SRLr_a();
            break;
        case 0xCB40:
            BIT0b();
            break;
        case 0xCB41:
            BIT0c();
            break;
        case 0xCB42:
            BIT0d();
            break;
        case 0xCB43:
            BIT0e();
            break;
        case 0xCB44:
            BIT0h();
            break;
        case 0xCB45:
            BIT0l();
            break;
        case 0xCB46:
            BIT0m();
            break;
        case 0xCB47:
            BIT0a();
            break;
        case 0xCB48:
            BIT1b();
            break;
        case 0xCB49:
            BIT1c();
            break;
        case 0xCB4A:
            BIT1d();
            break;
        case 0xCB4B:
            BIT1e();
            break;
        case 0xCB4C:
            BIT1h();
            break;
        case 0xCB4D:
            BIT1l();
            break;
        case 0xCB4E:
            BIT1m();
            break;
        case 0xCB4F:
            BIT1a();
            break;
        case 0xCB50:
            BIT2b();
            break;
        case 0xCB51:
            BIT2c();
            break;
        case 0xCB52:
            BIT2d();
            break;
        case 0xCB53:
            BIT2e();
            break;
        case 0xCB54:
            BIT2h();
            break;
        case 0xCB55:
            BIT2l();
            break;
        case 0xCB56:
            BIT2m();
            break;
        case 0xCB57:
            BIT2a();
            break;
        case 0xCB58:
            BIT3b();
            break;
        case 0xCB59:
            BIT3c();
            break;
        case 0xCB5A:
            BIT3d();
            break;
        case 0xCB5B:
            BIT3e();
            break;
        case 0xCB5C:
            BIT3h();
            break;
        case 0xCB5D:
            BIT3l();
            break;
        case 0xCB5E:
            BIT3m();
            break;
        case 0xCB5F:
            BIT3a();
            break;
        case 0xCB60:
            BIT4b();
            break;
        case 0xCB61:
            BIT4c();
            break;
        case 0xCB62:
            BIT4d();
            break;
        case 0xCB63:
            BIT4e();
            break;
        case 0xCB64:
            BIT4h();
            break;
        case 0xCB65:
            BIT4l();
            break;
        case 0xCB66:
            BIT4m();
            break;
        case 0xCB67:
            BIT4a();
            break;
        case 0xCB68:
            BIT5b();
            break;
        case 0xCB69:
            BIT5c();
            break;
        case 0xCB6A:
            BIT5d();
            break;
        case 0xCB6B:
            BIT5e();
            break;
        case 0xCB6C:
            BIT5h();
            break;
        case 0xCB6D:
            BIT5l();
            break;
        case 0xCB6E:
            BIT5m();
            break;
        case 0xCB6F:
            BIT5a();
            break;
        case 0xCB70:
            BIT6b();
            break;
        case 0xCB71:
            BIT6c();
            break;
        case 0xCB72:
            BIT6d();
            break;
        case 0xCB73:
            BIT6e();
            break;
        case 0xCB74:
            BIT6h();
            break;
        case 0xCB75:
            BIT6l();
            break;
        case 0xCB76:
            BIT6m();
            break;
        case 0xCB77:
            BIT6a();
            break;
        case 0xCB78:
            BIT7b();
            break;
        case 0xCB79:
            BIT7c();
            break;
        case 0xCB7A:
            BIT7d();
            break;
        case 0xCB7B:
            BIT7e();
            break;
        case 0xCB7C:
            BIT7h();
            break;
        case 0xCB7D:
            BIT7l();
            break;
        case 0xCB7E:
            BIT7m();
            break;
        case 0xCB7F:
            BIT7a();
            break;
        case 0xCB80:
            RES0b();
            break;
        case 0xCB81:
            RES0c();
            break;
        case 0xCB82:
            RES0d();
            break;
        case 0xCB83:
            RES0e();
            break;
        case 0xCB84:
            RES0h();
            break;
        case 0xCB85:
            RES0l();
            break;
        case 0xCB86:
            RES0m();
            break;
        case 0xCB87:
            RES0a();
            break;
        case 0xCB88:
            RES1b();
            break;
        case 0xCB89:
            RES1c();
            break;
        case 0xCB8A:
            RES1d();
            break;
        case 0xCB8B:
            RES1e();
            break;
        case 0xCB8C:
            RES1h();
            break;
        case 0xCB8D:
            RES1l();
            break;
        case 0xCB8E:
            RES1m();
            break;
        case 0xCB8F:
            RES1a();
            break;
        case 0xCB90:
            RES2b();
            break;
        case 0xCB91:
            RES2c();
            break;
        case 0xCB92:
            RES2d();
            break;
        case 0xCB93:
            RES2e();
            break;
        case 0xCB94:
            RES2h();
            break;
        case 0xCB95:
            RES2l();
            break;
        case 0xCB96:
            RES2m();
            break;
        case 0xCB97:
            RES2a();
            break;
        case 0xCB98:
            RES3b();
            break;
        case 0xCB99:
            RES3c();
            break;
        case 0xCB9A:
            RES3d();
            break;
        case 0xCB9B:
            RES3e();
            break;
        case 0xCB9C:
            RES3h();
            break;
        case 0xCB9D:
            RES3l();
            break;
        case 0xCB9E:
            RES3m();
            break;
        case 0xCB9F:
            RES3a();
            break;
        case 0xCBA0:
            RES4b();
            break;
        case 0xCBA1:
            RES4c();
            break;
        case 0xCBA2:
            RES4d();
            break;
        case 0xCBA3:
            RES4e();
            break;
        case 0xCBA4:
            RES4h();
            break;
        case 0xCBA5:
            RES4l();
            break;
        case 0xCBA6:
            RES4m();
            break;
        case 0xCBA7:
            RES4a();
            break;
        case 0xCBA8:
            RES5b();
            break;
        case 0xCBA9:
            RES5c();
            break;
        case 0xCBAA:
            RES5d();
            break;
        case 0xCBAB:
            RES5e();
            break;
        case 0xCBAC:
            RES5h();
            break;
        case 0xCBAD:
            RES5l();
            break;
        case 0xCBAE:
            RES5m();
            break;
        case 0xCBAF:
            RES5a();
            break;
        case 0xCBB0:
            RES6b();
            break;
        case 0xCBB1:
            RES6c();
            break;
        case 0xCBB2:
            RES6d();
            break;
        case 0xCBB3:
            RES6e();
            break;
        case 0xCBB4:
            RES6h();
            break;
        case 0xCBB5:
            RES6l();
            break;
        case 0xCBB6:
            RES6m();
            break;
        case 0xCBB7:
            RES6a();
            break;
        case 0xCBB8:
            RES7b();
            break;
        case 0xCBB9:
            RES7c();
            break;
        case 0xCBBA:
            RES7d();
            break;
        case 0xCBBB:
            RES7e();
            break;
        case 0xCBBC:
            RES7h();
            break;
        case 0xCBBD:
            RES7l();
            break;
        case 0xCBBE:
            RES7m();
            break;
        case 0xCBBF:
            RES7a();
            break;
        case 0xCBC0:
            SET0b();
            break;
        case 0xCBC1:
            SET0c();
            break;
        case 0xCBC2:
            SET0d();
            break;
        case 0xCBC3:
            SET0e();
            break;
        case 0xCBC4:
            SET0h();
            break;
        case 0xCBC5:
            SET0l();
            break;
        case 0xCBC6:
            SET0m();
            break;
        case 0xCBC7:
            SET0a();
            break;
        case 0xCBC8:
            SET1b();
            break;
        case 0xCBC9:
            SET1c();
            break;
        case 0xCBCA:
            SET1d();
            break;
        case 0xCBCB:
            SET1e();
            break;
        case 0xCBCC:
            SET1h();
            break;
        case 0xCBCD:
            SET1l();
            break;
        case 0xCBCE:
            SET1m();
            break;
        case 0xCBCF:
            SET1a();
            break;
        case 0xCBD0:
            SET2b();
            break;
        case 0xCBD1:
            SET2c();
            break;
        case 0xCBD2:
            SET2d();
            break;
        case 0xCBD3:
            SET2e();
            break;
        case 0xCBD4:
            SET2h();
            break;
        case 0xCBD5:
            SET2l();
            break;
        case 0xCBD6:
            SET2m();
            break;
        case 0xCBD7:
            SET2a();
            break;
        case 0xCBD8:
            SET3b();
            break;
        case 0xCBD9:
            SET3c();
            break;
        case 0xCBDA:
            SET3d();
            break;
        case 0xCBDB:
            SET3e();
            break;
        case 0xCBDC:
            SET3h();
            break;
        case 0xCBDD:
            SET3l();
            break;
        case 0xCBDE:
            SET3m();
            break;
        case 0xCBDF:
            SET3a();
            break;
        case 0xCBE0:
            SET4b();
            break;
        case 0xCBE1:
            SET4c();
            break;
        case 0xCBE2:
            SET4d();
            break;
        case 0xCBE3:
            SET4e();
            break;
        case 0xCBE4:
            SET4h();
            break;
        case 0xCBE5:
            SET4l();
            break;
        case 0xCBE6:
            SET4m();
            break;
        case 0xCBE7:
            SET4a();
            break;
        case 0xCBE8:
            SET5b();
            break;
        case 0xCBE9:
            SET5c();
            break;
        case 0xCBEA:
            SET5d();
            break;
        case 0xCBEB:
            SET5e();
            break;
        case 0xCBEC:
            SET5h();
            break;
        case 0xCBED:
            SET5l();
            break;
        case 0xCBEE:
            SET5m();
            break;
        case 0xCBEF:
            SET5a();
            break;
        case 0xCBF0:
            SET6b();
            break;
        case 0xCBF1:
            SET6c();
            break;
        case 0xCBF2:
            SET6d();
            break;
        case 0xCBF3:
            SET6e();
            break;
        case 0xCBF4:
            SET6h();
            break;
        case 0xCBF5:
            SET6l();
            break;
        case 0xCBF6:
            SET6m();
            break;
        case 0xCBF7:
            SET6a();
            break;
        case 0xCBF8:
            SET7b();
            break;
        case 0xCBF9:
            SET7c();
            break;
        case 0xCBFA:
            SET7d();
            break;
        case 0xCBFB:
            SET7e();
            break;
        case 0xCBFC:
            SET7h();
            break;
        case 0xCBFD:
            SET7l();
            break;
        case 0xCBFE:
            SET7m();
            break;
        case 0xCBFF:
            SET7a();
            break;
        default:
            throw std::runtime_error("CB OpCode: '" + ToHexString(op_code) + "'\n");
    }
    UpdateClock();
}

int16_t CPU::GetNextPC() {
    return registers.pc++;
}

int16_t CPU::GetCurrentPC() const {
    return registers.pc;
}

void CPU::SetMMU(MMU& mmu) {
    this->mmu = &mmu;
}

void CPU::UpdateClock() {
    clock.m += registers.m;
    clock.t += registers.t;
}

void CPU::Reset() {
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

void CPU::LDrr_bb() { registers.b=registers.b; registers.m=1; }
void CPU::LDrr_bc() { registers.b=registers.c; registers.m=1; }
void CPU::LDrr_bd() { registers.b=registers.d; registers.m=1; }
void CPU::LDrr_be() { registers.b=registers.e; registers.m=1; }
void CPU::LDrr_bh() { registers.b=registers.h; registers.m=1; }
void CPU::LDrr_bl() { registers.b=registers.l; registers.m=1; }
void CPU::LDrr_ba() { registers.b=registers.a; registers.m=1; }
void CPU::LDrr_cb() { registers.c=registers.b; registers.m=1; }
void CPU::LDrr_cc() { registers.c=registers.c; registers.m=1; }
void CPU::LDrr_cd() { registers.c=registers.d; registers.m=1; }
void CPU::LDrr_ce() { registers.c=registers.e; registers.m=1; }
void CPU::LDrr_ch() { registers.c=registers.h; registers.m=1; }
void CPU::LDrr_cl() { registers.c=registers.l; registers.m=1; }
void CPU::LDrr_ca() { registers.c=registers.a; registers.m=1; }
void CPU::LDrr_db() { registers.d=registers.b; registers.m=1; }
void CPU::LDrr_dc() { registers.d=registers.c; registers.m=1; }
void CPU::LDrr_dd() { registers.d=registers.d; registers.m=1; }
void CPU::LDrr_de() { registers.d=registers.e; registers.m=1; }
void CPU::LDrr_dh() { registers.d=registers.h; registers.m=1; }
void CPU::LDrr_dl() { registers.d=registers.l; registers.m=1; }
void CPU::LDrr_da() { registers.d=registers.a; registers.m=1; }
void CPU::LDrr_eb() { registers.e=registers.b; registers.m=1; }
void CPU::LDrr_ec() { registers.e=registers.c; registers.m=1; }
void CPU::LDrr_ed() { registers.e=registers.d; registers.m=1; }
void CPU::LDrr_ee() { registers.e=registers.e; registers.m=1; }
void CPU::LDrr_eh() { registers.e=registers.h; registers.m=1; }
void CPU::LDrr_el() { registers.e=registers.l; registers.m=1; }
void CPU::LDrr_ea() { registers.e=registers.a; registers.m=1; }
void CPU::LDrr_hb() { registers.h=registers.b; registers.m=1; }
void CPU::LDrr_hc() { registers.h=registers.c; registers.m=1; }
void CPU::LDrr_hd() { registers.h=registers.d; registers.m=1; }
void CPU::LDrr_he() { registers.h=registers.e; registers.m=1; }
void CPU::LDrr_hh() { registers.h=registers.h; registers.m=1; }
void CPU::LDrr_hl() { registers.h=registers.l; registers.m=1; }
void CPU::LDrr_ha() { registers.h=registers.a; registers.m=1; }
void CPU::LDrr_lb() { registers.l=registers.b; registers.m=1; }
void CPU::LDrr_lc() { registers.l=registers.c; registers.m=1; }
void CPU::LDrr_ld() { registers.l=registers.d; registers.m=1; }
void CPU::LDrr_le() { registers.l=registers.e; registers.m=1; }
void CPU::LDrr_lh() { registers.l=registers.h; registers.m=1; }
void CPU::LDrr_ll() { registers.l=registers.l; registers.m=1; }
void CPU::LDrr_la() { registers.l=registers.a; registers.m=1; }
void CPU::LDrr_ab() { registers.a=registers.b; registers.m=1; }
void CPU::LDrr_ac() { registers.a=registers.c; registers.m=1; }
void CPU::LDrr_ad() { registers.a=registers.d; registers.m=1; }
void CPU::LDrr_ae() { registers.a=registers.e; registers.m=1; }
void CPU::LDrr_ah() { registers.a=registers.h; registers.m=1; }
void CPU::LDrr_al() { registers.a=registers.l; registers.m=1; }
void CPU::LDrr_aa() { registers.a=registers.a; registers.m=1; }

void CPU::LDrHLm_b() { registers.b=mmu->ReadByte((registers.h<<8)+registers.l); registers.m=2; }
void CPU::LDrHLm_c() { registers.c=mmu->ReadByte((registers.h<<8)+registers.l); registers.m=2; }
void CPU::LDrHLm_d() { registers.d=mmu->ReadByte((registers.h<<8)+registers.l); registers.m=2; }
void CPU::LDrHLm_e() { registers.e=mmu->ReadByte((registers.h<<8)+registers.l); registers.m=2; }
void CPU::LDrHLm_h() { registers.h=mmu->ReadByte((registers.h<<8)+registers.l); registers.m=2; }
void CPU::LDrHLm_l() { registers.l=mmu->ReadByte((registers.h<<8)+registers.l); registers.m=2; }
void CPU::LDrHLm_a() { registers.a=mmu->ReadByte((registers.h<<8)+registers.l); registers.m=2; }

void CPU::LDHLmr_b() { mmu->WriteByte((registers.h<<8)+registers.l,registers.b); registers.m=2; }
void CPU::LDHLmr_c() { mmu->WriteByte((registers.h<<8)+registers.l,registers.c); registers.m=2; }
void CPU::LDHLmr_d() { mmu->WriteByte((registers.h<<8)+registers.l,registers.d); registers.m=2; }
void CPU::LDHLmr_e() { mmu->WriteByte((registers.h<<8)+registers.l,registers.e); registers.m=2; }
void CPU::LDHLmr_h() { mmu->WriteByte((registers.h<<8)+registers.l,registers.h); registers.m=2; }
void CPU::LDHLmr_l() { mmu->WriteByte((registers.h<<8)+registers.l,registers.l); registers.m=2; }
void CPU::LDHLmr_a() { mmu->WriteByte((registers.h<<8)+registers.l,registers.a); registers.m=2; }

void CPU::LDrn_b() { registers.b=mmu->ReadByte(registers.pc); registers.pc++; registers.m=2; }
void CPU::LDrn_c() { registers.c=mmu->ReadByte(registers.pc); registers.pc++; registers.m=2; }
void CPU::LDrn_d() { registers.d=mmu->ReadByte(registers.pc); registers.pc++; registers.m=2; }
void CPU::LDrn_e() { registers.e=mmu->ReadByte(registers.pc); registers.pc++; registers.m=2; }
void CPU::LDrn_h() { registers.h=mmu->ReadByte(registers.pc); registers.pc++; registers.m=2; }
void CPU::LDrn_l() { registers.l=mmu->ReadByte(registers.pc); registers.pc++; registers.m=2; }
void CPU::LDrn_a() { registers.a=mmu->ReadByte(registers.pc); registers.pc++; registers.m=2; }

void CPU::LDHLmn() { mmu->WriteByte((registers.h<<8)+registers.l, mmu->ReadByte(registers.pc)); registers.pc++; registers.m=3; }

void CPU::LDBCmA() { mmu->WriteByte((registers.b<<8)+registers.c, registers.a); registers.m=2; }
void CPU::LDDEmA() { mmu->WriteByte((registers.d<<8)+registers.e, registers.a); registers.m=2; }

void CPU::LDmmA() { mmu->WriteByte(mmu->ReadWord(registers.pc), registers.a); registers.pc+=2; registers.m=4; }

void CPU::LDABCm() { registers.a=mmu->ReadByte((registers.b<<8)+registers.c); registers.m=2; }
void CPU::LDADEm() { registers.a=mmu->ReadByte((registers.d<<8)+registers.e); registers.m=2; }

void CPU::LDAmm() { registers.a=mmu->ReadByte(mmu->ReadWord(registers.pc)); registers.pc+=2; registers.m=4; }

void CPU::LDBCnn() { registers.c=mmu->ReadByte(registers.pc); registers.b=mmu->ReadByte(registers.pc+1); registers.pc+=2; registers.m=3; }
void CPU::LDDEnn() { registers.e=mmu->ReadByte(registers.pc); registers.d=mmu->ReadByte(registers.pc+1); registers.pc+=2; registers.m=3; }
void CPU::LDHLnn() { registers.l=mmu->ReadByte(registers.pc); registers.h=mmu->ReadByte(registers.pc+1); registers.pc+=2; registers.m=3; }
void CPU::LDSPnn() { registers.sp=mmu->ReadWord(registers.pc); registers.pc+=2; registers.m=3; }

void CPU::LDHLmm() { auto i=mmu->ReadWord(registers.pc); registers.pc+=2; registers.l=mmu->ReadByte(i); registers.h=mmu->ReadByte(i+1); registers.m=5; }
void CPU::LDmmHL() { auto i=mmu->ReadWord(registers.pc); registers.pc+=2; mmu->WriteWord(i,(registers.h<<8)+registers.l); registers.m=5; }

void CPU::LDHLIA() { mmu->WriteByte((registers.h<<8)+registers.l, registers.a); registers.l=(registers.l+1)&255; if(!registers.l) registers.h=(registers.h+1)&255; registers.m=2; }
void CPU::LDAHLI() { registers.a=mmu->ReadByte((registers.h<<8)+registers.l); registers.l=(registers.l+1)&255; if(!registers.l) registers.h=(registers.h+1)&255; registers.m=2; }

void CPU::LDHLDA() { mmu->WriteByte((registers.h<<8)+registers.l, registers.a); registers.l=(registers.l-1)&255; if(registers.l==255) registers.h=(registers.h-1)&255; registers.m=2; }
void CPU::LDAHLD() { registers.a=mmu->ReadByte((registers.h<<8)+registers.l); registers.l=(registers.l-1)&255; if(registers.l==255) registers.h=(registers.h-1)&255; registers.m=2; }

void CPU::LDAIOn() { registers.a=mmu->ReadByte(0xFF00+mmu->ReadByte(registers.pc)); registers.pc++; registers.m=3; }
void CPU::LDIOnA() { mmu->WriteByte(0xFF00+mmu->ReadByte(registers.pc),registers.a); registers.pc++; registers.m=3; }
void CPU::LDAIOC() { registers.a=mmu->ReadByte(0xFF00+registers.c); registers.m=2; }
void CPU::LDIOCA() { mmu->WriteByte(0xFF00+registers.c,registers.a); registers.m=2; }

void CPU::LDHLSPn() { auto i=mmu->ReadByte(registers.pc); if(i>127) i=-((~i+1)&255); registers.pc++; i+=registers.sp; registers.h=(i>>8)&255; registers.l=i&255; registers.m=3; }

void CPU::SWAPr_b() { auto tr=registers.b; registers.b=((tr&0xF)<<4)|((tr&0xF0)>>4); registers.f=registers.b?0:0x80; registers.m=1; }
void CPU::SWAPr_c() { auto tr=registers.c; registers.c=((tr&0xF)<<4)|((tr&0xF0)>>4); registers.f=registers.c?0:0x80; registers.m=1; }
void CPU::SWAPr_d() { auto tr=registers.d; registers.d=((tr&0xF)<<4)|((tr&0xF0)>>4); registers.f=registers.d?0:0x80; registers.m=1; }
void CPU::SWAPr_e() { auto tr=registers.e; registers.e=((tr&0xF)<<4)|((tr&0xF0)>>4); registers.f=registers.e?0:0x80; registers.m=1; }
void CPU::SWAPr_h() { auto tr=registers.h; registers.h=((tr&0xF)<<4)|((tr&0xF0)>>4); registers.f=registers.h?0:0x80; registers.m=1; }
void CPU::SWAPr_l() { auto tr=registers.l; registers.l=((tr&0xF)<<4)|((tr&0xF0)>>4); registers.f=registers.l?0:0x80; registers.m=1; }
void CPU::SWAPr_a() { auto tr=registers.a; registers.a=((tr&0xF)<<4)|((tr&0xF0)>>4); registers.f=registers.a?0:0x80; registers.m=1; }

/*--- Data processing ---*/
void CPU::ADDr_b() { auto a=registers.a; registers.a+=registers.b; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.b^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADDr_c() { auto a=registers.a; registers.a+=registers.c; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.c^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADDr_d() { auto a=registers.a; registers.a+=registers.d; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.d^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADDr_e() { auto a=registers.a; registers.a+=registers.e; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.e^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADDr_h() { auto a=registers.a; registers.a+=registers.h; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.h^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADDr_l() { auto a=registers.a; registers.a+=registers.l; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.l^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADDr_a() { auto a=registers.a; registers.a+=registers.a; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.a^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADDHL() { auto a=registers.a; auto m=mmu->ReadByte((registers.h<<8)+registers.l); registers.a+=m; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^a^m)&0x10) registers.f|=0x20; registers.m=2; }
void CPU::ADDn() { auto a=registers.a; auto m=mmu->ReadByte(registers.pc); registers.a+=m; registers.pc++; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^a^m)&0x10) registers.f|=0x20; registers.m=2; }
void CPU::ADDHLBC() { auto hl=(registers.h<<8)+registers.l; hl+=(registers.b<<8)+registers.c; if(hl>65535) registers.f|=0x10; else registers.f&=0xEF; registers.h=(hl>>8)&255; registers.l=hl&255; registers.m=3; }
void CPU::ADDHLDE() { auto hl=(registers.h<<8)+registers.l; hl+=(registers.d<<8)+registers.e; if(hl>65535) registers.f|=0x10; else registers.f&=0xEF; registers.h=(hl>>8)&255; registers.l=hl&255; registers.m=3; }
void CPU::ADDHLHL() { auto hl=(registers.h<<8)+registers.l; hl+=(registers.h<<8)+registers.l; if(hl>65535) registers.f|=0x10; else registers.f&=0xEF; registers.h=(hl>>8)&255; registers.l=hl&255; registers.m=3; }
void CPU::ADDHLSP() { auto hl=(registers.h<<8)+registers.l; hl+=registers.sp; if(hl>65535) registers.f|=0x10; else registers.f&=0xEF; registers.h=(hl>>8)&255; registers.l=hl&255; registers.m=3; }
void CPU::ADDSPn() { auto i=mmu->ReadByte(registers.pc); if(i>127) i=-((~i+1)&255); registers.pc++; registers.sp+=i; registers.m=4; }

void CPU::ADCr_b() { auto a=registers.a; registers.a+=registers.b; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.b^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADCr_c() { auto a=registers.a; registers.a+=registers.c; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.c^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADCr_d() { auto a=registers.a; registers.a+=registers.d; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.d^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADCr_e() { auto a=registers.a; registers.a+=registers.e; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.e^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADCr_h() { auto a=registers.a; registers.a+=registers.h; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.h^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADCr_l() { auto a=registers.a; registers.a+=registers.l; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.l^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADCr_a() { auto a=registers.a; registers.a+=registers.a; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.a^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::ADCHL() { auto a=registers.a; auto m=mmu->ReadByte((registers.h<<8)+registers.l); registers.a+=m; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^m^a)&0x10) registers.f|=0x20; registers.m=2; }
void CPU::ADCn() { auto a=registers.a; auto m=mmu->ReadByte(registers.pc); registers.a+=m; registers.pc++; registers.a+=(registers.f&0x10)?1:0; registers.f=(registers.a>255)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^m^a)&0x10) registers.f|=0x20; registers.m=2; }

void CPU::SUBr_b() { auto a=registers.a; registers.a-=registers.b; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.b^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SUBr_c() { auto a=registers.a; registers.a-=registers.c; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.c^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SUBr_d() { auto a=registers.a; registers.a-=registers.d; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.d^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SUBr_e() { auto a=registers.a; registers.a-=registers.e; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.e^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SUBr_h() { auto a=registers.a; registers.a-=registers.h; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.h^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SUBr_l() { auto a=registers.a; registers.a-=registers.l; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.l^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SUBr_a() { auto a=registers.a; registers.a-=registers.a; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.a^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SUBHL() { auto a=registers.a; auto m=mmu->ReadByte((registers.h<<8)+registers.l); registers.a-=m; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^m^a)&0x10) registers.f|=0x20; registers.m=2; }
void CPU::SUBn() { auto a=registers.a; auto m=mmu->ReadByte(registers.pc); registers.a-=m; registers.pc++; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^m^a)&0x10) registers.f|=0x20; registers.m=2; }

void CPU::SBCr_b() { auto a=registers.a; registers.a-=registers.b; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.b^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SBCr_c() { auto a=registers.a; registers.a-=registers.c; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.c^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SBCr_d() { auto a=registers.a; registers.a-=registers.d; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.d^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SBCr_e() { auto a=registers.a; registers.a-=registers.e; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.e^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SBCr_h() { auto a=registers.a; registers.a-=registers.h; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.h^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SBCr_l() { auto a=registers.a; registers.a-=registers.l; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.l^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SBCr_a() { auto a=registers.a; registers.a-=registers.a; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^registers.a^a)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::SBCHL() { auto a=registers.a; auto m=mmu->ReadByte((registers.h<<8)+registers.l); registers.a-=m; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^m^a)&0x10) registers.f|=0x20; registers.m=2; }
void CPU::SBCn() { auto a=registers.a; auto m=mmu->ReadByte(registers.pc); registers.a-=m; registers.pc++; registers.a-=(registers.f&0x10)?1:0; registers.f=(registers.a<0)?0x50:0x40; registers.a&=255; if(!registers.a) registers.f|=0x80; if((registers.a^m^a)&0x10) registers.f|=0x20; registers.m=2; }

void CPU::CPr_b() { auto i=registers.a; i-=registers.b; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^registers.b^i)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::CPr_c() { auto i=registers.a; i-=registers.c; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^registers.c^i)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::CPr_d() { auto i=registers.a; i-=registers.d; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^registers.d^i)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::CPr_e() { auto i=registers.a; i-=registers.e; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^registers.e^i)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::CPr_h() { auto i=registers.a; i-=registers.h; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^registers.h^i)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::CPr_l() { auto i=registers.a; i-=registers.l; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^registers.l^i)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::CPr_a() { auto i=registers.a; i-=registers.a; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^registers.a^i)&0x10) registers.f|=0x20; registers.m=1; }
void CPU::CPHL() { auto i=registers.a; auto m=mmu->ReadByte((registers.h<<8)+registers.l); i-=m; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^i^m)&0x10) registers.f|=0x20; registers.m=2; }
void CPU::CPn() { auto i=registers.a; auto m=mmu->ReadByte(registers.pc); i-=m; registers.pc++; registers.f=(i<0)?0x50:0x40; i&=255; if(!i) registers.f|=0x80; if((registers.a^i^m)&0x10) registers.f|=0x20; registers.m=2; }

void CPU::DAA() { auto a=registers.a; if((registers.f&0x20)||((registers.a&15)>9)) registers.a+=6; registers.f&=0xEF; if((registers.f&0x20)||(a>0x99)) { registers.a+=0x60; registers.f|=0x10; } registers.m=1; }

void CPU::ANDr_b() { registers.a&=registers.b; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ANDr_c() { registers.a&=registers.c; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ANDr_d() { registers.a&=registers.d; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ANDr_e() { registers.a&=registers.e; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ANDr_h() { registers.a&=registers.h; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ANDr_l() { registers.a&=registers.l; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ANDr_a() { registers.a&=registers.a; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ANDHL() { registers.a&=mmu->ReadByte((registers.h<<8)+registers.l); registers.a&=255; registers.f=registers.a?0:0x80; registers.m=2; }
void CPU::ANDn() { registers.a&=mmu->ReadByte(registers.pc); registers.pc++; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=2; }

void CPU::ORr_b() { registers.a|=registers.b; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ORr_c() { registers.a|=registers.c; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ORr_d() { registers.a|=registers.d; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ORr_e() { registers.a|=registers.e; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ORr_h() { registers.a|=registers.h; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ORr_l() { registers.a|=registers.l; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ORr_a() { registers.a|=registers.a; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::ORHL() { registers.a|=mmu->ReadByte((registers.h<<8)+registers.l); registers.a&=255; registers.f=registers.a?0:0x80; registers.m=2; }
void CPU::ORn() { registers.a|=mmu->ReadByte(registers.pc); registers.pc++; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=2; }

void CPU::XORr_b() { registers.a^=registers.b; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::XORr_c() { registers.a^=registers.c; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::XORr_d() { registers.a^=registers.d; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::XORr_e() { registers.a^=registers.e; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::XORr_h() { registers.a^=registers.h; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::XORr_l() { registers.a^=registers.l; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::XORr_a() { registers.a^=registers.a; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::XORHL() { registers.a^=mmu->ReadByte((registers.h<<8)+registers.l); registers.a&=255; registers.f=registers.a?0:0x80; registers.m=2; }
void CPU::XORn() { registers.a^=mmu->ReadByte(registers.pc); registers.pc++; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=2; }

void CPU::INCr_b() { registers.b++; registers.b&=255; registers.f=registers.b?0:0x80; registers.m=1; }
void CPU::INCr_c() { registers.c++; registers.c&=255; registers.f=registers.c?0:0x80; registers.m=1; }
void CPU::INCr_d() { registers.d++; registers.d&=255; registers.f=registers.d?0:0x80; registers.m=1; }
void CPU::INCr_e() { registers.e++; registers.e&=255; registers.f=registers.e?0:0x80; registers.m=1; }
void CPU::INCr_h() { registers.h++; registers.h&=255; registers.f=registers.h?0:0x80; registers.m=1; }
void CPU::INCr_l() { registers.l++; registers.l&=255; registers.f=registers.l?0:0x80; registers.m=1; }
void CPU::INCr_a() { registers.a++; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::INCHLm() { auto i=mmu->ReadByte((registers.h<<8)+registers.l)+1; i&=255; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.f=i?0:0x80; registers.m=3; }

void CPU::DECr_b() { registers.b--; registers.b&=255; registers.f=registers.b?0:0x80; registers.m=1; }
void CPU::DECr_c() { registers.c--; registers.c&=255; registers.f=registers.c?0:0x80; registers.m=1; }
void CPU::DECr_d() { registers.d--; registers.d&=255; registers.f=registers.d?0:0x80; registers.m=1; }
void CPU::DECr_e() { registers.e--; registers.e&=255; registers.f=registers.e?0:0x80; registers.m=1; }
void CPU::DECr_h() { registers.h--; registers.h&=255; registers.f=registers.h?0:0x80; registers.m=1; }
void CPU::DECr_l() { registers.l--; registers.l&=255; registers.f=registers.l?0:0x80; registers.m=1; }
void CPU::DECr_a() { registers.a--; registers.a&=255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::DECHLm() { auto i=mmu->ReadByte((registers.h<<8)+registers.l)-1; i&=255; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.f=i?0:0x80; registers.m=3; }

void CPU::INCBC() { registers.c=(registers.c+1)&255; if(!registers.c) registers.b=(registers.b+1)&255; registers.m=1; }
void CPU::INCDE() { registers.e=(registers.e+1)&255; if(!registers.e) registers.d=(registers.d+1)&255; registers.m=1; }
void CPU::INCHL() { registers.l=(registers.l+1)&255; if(!registers.l) registers.h=(registers.h+1)&255; registers.m=1; }
void CPU::INCSP() { registers.sp=(registers.sp+1)&65535; registers.m=1; }

void CPU::DECBC() { registers.c=(registers.c-1)&255; if(registers.c==255) registers.b=(registers.b-1)&255; registers.m=1; }
void CPU::DECDE() { registers.e=(registers.e-1)&255; if(registers.e==255) registers.d=(registers.d-1)&255; registers.m=1; }
void CPU::DECHL() { registers.l=(registers.l-1)&255; if(registers.l==255) registers.h=(registers.h-1)&255; registers.m=1; }
void CPU::DECSP() { registers.sp=(registers.sp-1)&65535; registers.m=1; }

/*--- Bit manipulation ---*/
void CPU::BIT0b() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.b&0x01)?0:0x80; registers.m=2; }
void CPU::BIT0c() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.c&0x01)?0:0x80; registers.m=2; }
void CPU::BIT0d() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.d&0x01)?0:0x80; registers.m=2; }
void CPU::BIT0e() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.e&0x01)?0:0x80; registers.m=2; }
void CPU::BIT0h() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.h&0x01)?0:0x80; registers.m=2; }
void CPU::BIT0l() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.l&0x01)?0:0x80; registers.m=2; }
void CPU::BIT0a() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.a&0x01)?0:0x80; registers.m=2; }
void CPU::BIT0m() { registers.f&=0x1F; registers.f|=0x20; registers.f=(mmu->ReadByte((registers.h<<8)+registers.l)&0x01)?0:0x80; registers.m=3; }

void CPU::RES0b() { registers.b&=0xFE; registers.m=2; }
void CPU::RES0c() { registers.c&=0xFE; registers.m=2; }
void CPU::RES0d() { registers.d&=0xFE; registers.m=2; }
void CPU::RES0e() { registers.e&=0xFE; registers.m=2; }
void CPU::RES0h() { registers.h&=0xFE; registers.m=2; }
void CPU::RES0l() { registers.l&=0xFE; registers.m=2; }
void CPU::RES0a() { registers.a&=0xFE; registers.m=2; }
void CPU::RES0m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i&=0xFE; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::SET0b() { registers.b|=0x01; registers.m=2; }
void CPU::SET0c() { registers.b|=0x01; registers.m=2; }
void CPU::SET0d() { registers.b|=0x01; registers.m=2; }
void CPU::SET0e() { registers.b|=0x01; registers.m=2; }
void CPU::SET0h() { registers.b|=0x01; registers.m=2; }
void CPU::SET0l() { registers.b|=0x01; registers.m=2; }
void CPU::SET0a() { registers.b|=0x01; registers.m=2; }
void CPU::SET0m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i|=0x01; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::BIT1b() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.b&0x02)?0:0x80; registers.m=2; }
void CPU::BIT1c() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.c&0x02)?0:0x80; registers.m=2; }
void CPU::BIT1d() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.d&0x02)?0:0x80; registers.m=2; }
void CPU::BIT1e() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.e&0x02)?0:0x80; registers.m=2; }
void CPU::BIT1h() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.h&0x02)?0:0x80; registers.m=2; }
void CPU::BIT1l() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.l&0x02)?0:0x80; registers.m=2; }
void CPU::BIT1a() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.a&0x02)?0:0x80; registers.m=2; }
void CPU::BIT1m() { registers.f&=0x1F; registers.f|=0x20; registers.f=(mmu->ReadByte((registers.h<<8)+registers.l)&0x02)?0:0x80; registers.m=3; }

void CPU::RES1b() { registers.b&=0xFD; registers.m=2; }
void CPU::RES1c() { registers.c&=0xFD; registers.m=2; }
void CPU::RES1d() { registers.d&=0xFD; registers.m=2; }
void CPU::RES1e() { registers.e&=0xFD; registers.m=2; }
void CPU::RES1h() { registers.h&=0xFD; registers.m=2; }
void CPU::RES1l() { registers.l&=0xFD; registers.m=2; }
void CPU::RES1a() { registers.a&=0xFD; registers.m=2; }
void CPU::RES1m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i&=0xFD; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::SET1b() { registers.b|=0x02; registers.m=2; }
void CPU::SET1c() { registers.b|=0x02; registers.m=2; }
void CPU::SET1d() { registers.b|=0x02; registers.m=2; }
void CPU::SET1e() { registers.b|=0x02; registers.m=2; }
void CPU::SET1h() { registers.b|=0x02; registers.m=2; }
void CPU::SET1l() { registers.b|=0x02; registers.m=2; }
void CPU::SET1a() { registers.b|=0x02; registers.m=2; }
void CPU::SET1m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i|=0x02; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::BIT2b() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.b&0x04)?0:0x80; registers.m=2; }
void CPU::BIT2c() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.c&0x04)?0:0x80; registers.m=2; }
void CPU::BIT2d() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.d&0x04)?0:0x80; registers.m=2; }
void CPU::BIT2e() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.e&0x04)?0:0x80; registers.m=2; }
void CPU::BIT2h() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.h&0x04)?0:0x80; registers.m=2; }
void CPU::BIT2l() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.l&0x04)?0:0x80; registers.m=2; }
void CPU::BIT2a() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.a&0x04)?0:0x80; registers.m=2; }
void CPU::BIT2m() { registers.f&=0x1F; registers.f|=0x20; registers.f=(mmu->ReadByte((registers.h<<8)+registers.l)&0x04)?0:0x80; registers.m=3; }

void CPU::RES2b() { registers.b&=0xFB; registers.m=2; }
void CPU::RES2c() { registers.c&=0xFB; registers.m=2; }
void CPU::RES2d() { registers.d&=0xFB; registers.m=2; }
void CPU::RES2e() { registers.e&=0xFB; registers.m=2; }
void CPU::RES2h() { registers.h&=0xFB; registers.m=2; }
void CPU::RES2l() { registers.l&=0xFB; registers.m=2; }
void CPU::RES2a() { registers.a&=0xFB; registers.m=2; }
void CPU::RES2m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i&=0xFB; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::SET2b() { registers.b|=0x04; registers.m=2; }
void CPU::SET2c() { registers.b|=0x04; registers.m=2; }
void CPU::SET2d() { registers.b|=0x04; registers.m=2; }
void CPU::SET2e() { registers.b|=0x04; registers.m=2; }
void CPU::SET2h() { registers.b|=0x04; registers.m=2; }
void CPU::SET2l() { registers.b|=0x04; registers.m=2; }
void CPU::SET2a() { registers.b|=0x04; registers.m=2; }
void CPU::SET2m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i|=0x04; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::BIT3b() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.b&0x08)?0:0x80; registers.m=2; }
void CPU::BIT3c() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.c&0x08)?0:0x80; registers.m=2; }
void CPU::BIT3d() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.d&0x08)?0:0x80; registers.m=2; }
void CPU::BIT3e() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.e&0x08)?0:0x80; registers.m=2; }
void CPU::BIT3h() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.h&0x08)?0:0x80; registers.m=2; }
void CPU::BIT3l() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.l&0x08)?0:0x80; registers.m=2; }
void CPU::BIT3a() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.a&0x08)?0:0x80; registers.m=2; }
void CPU::BIT3m() { registers.f&=0x1F; registers.f|=0x20; registers.f=(mmu->ReadByte((registers.h<<8)+registers.l)&0x08)?0:0x80; registers.m=3; }

void CPU::RES3b() { registers.b&=0xF7; registers.m=2; }
void CPU::RES3c() { registers.c&=0xF7; registers.m=2; }
void CPU::RES3d() { registers.d&=0xF7; registers.m=2; }
void CPU::RES3e() { registers.e&=0xF7; registers.m=2; }
void CPU::RES3h() { registers.h&=0xF7; registers.m=2; }
void CPU::RES3l() { registers.l&=0xF7; registers.m=2; }
void CPU::RES3a() { registers.a&=0xF7; registers.m=2; }
void CPU::RES3m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i&=0xF7; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::SET3b() { registers.b|=0x08; registers.m=2; }
void CPU::SET3c() { registers.b|=0x08; registers.m=2; }
void CPU::SET3d() { registers.b|=0x08; registers.m=2; }
void CPU::SET3e() { registers.b|=0x08; registers.m=2; }
void CPU::SET3h() { registers.b|=0x08; registers.m=2; }
void CPU::SET3l() { registers.b|=0x08; registers.m=2; }
void CPU::SET3a() { registers.b|=0x08; registers.m=2; }
void CPU::SET3m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i|=0x08; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::BIT4b() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.b&0x10)?0:0x80; registers.m=2; }
void CPU::BIT4c() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.c&0x10)?0:0x80; registers.m=2; }
void CPU::BIT4d() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.d&0x10)?0:0x80; registers.m=2; }
void CPU::BIT4e() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.e&0x10)?0:0x80; registers.m=2; }
void CPU::BIT4h() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.h&0x10)?0:0x80; registers.m=2; }
void CPU::BIT4l() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.l&0x10)?0:0x80; registers.m=2; }
void CPU::BIT4a() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.a&0x10)?0:0x80; registers.m=2; }
void CPU::BIT4m() { registers.f&=0x1F; registers.f|=0x20; registers.f=(mmu->ReadByte((registers.h<<8)+registers.l)&0x10)?0:0x80; registers.m=3; }

void CPU::RES4b() { registers.b&=0xEF; registers.m=2; }
void CPU::RES4c() { registers.c&=0xEF; registers.m=2; }
void CPU::RES4d() { registers.d&=0xEF; registers.m=2; }
void CPU::RES4e() { registers.e&=0xEF; registers.m=2; }
void CPU::RES4h() { registers.h&=0xEF; registers.m=2; }
void CPU::RES4l() { registers.l&=0xEF; registers.m=2; }
void CPU::RES4a() { registers.a&=0xEF; registers.m=2; }
void CPU::RES4m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i&=0xEF; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::SET4b() { registers.b|=0x10; registers.m=2; }
void CPU::SET4c() { registers.b|=0x10; registers.m=2; }
void CPU::SET4d() { registers.b|=0x10; registers.m=2; }
void CPU::SET4e() { registers.b|=0x10; registers.m=2; }
void CPU::SET4h() { registers.b|=0x10; registers.m=2; }
void CPU::SET4l() { registers.b|=0x10; registers.m=2; }
void CPU::SET4a() { registers.b|=0x10; registers.m=2; }
void CPU::SET4m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i|=0x10; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::BIT5b() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.b&0x20)?0:0x80; registers.m=2; }
void CPU::BIT5c() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.c&0x20)?0:0x80; registers.m=2; }
void CPU::BIT5d() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.d&0x20)?0:0x80; registers.m=2; }
void CPU::BIT5e() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.e&0x20)?0:0x80; registers.m=2; }
void CPU::BIT5h() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.h&0x20)?0:0x80; registers.m=2; }
void CPU::BIT5l() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.l&0x20)?0:0x80; registers.m=2; }
void CPU::BIT5a() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.a&0x20)?0:0x80; registers.m=2; }
void CPU::BIT5m() { registers.f&=0x1F; registers.f|=0x20; registers.f=(mmu->ReadByte((registers.h<<8)+registers.l)&0x20)?0:0x80; registers.m=3; }

void CPU::RES5b() { registers.b&=0xDF; registers.m=2; }
void CPU::RES5c() { registers.c&=0xDF; registers.m=2; }
void CPU::RES5d() { registers.d&=0xDF; registers.m=2; }
void CPU::RES5e() { registers.e&=0xDF; registers.m=2; }
void CPU::RES5h() { registers.h&=0xDF; registers.m=2; }
void CPU::RES5l() { registers.l&=0xDF; registers.m=2; }
void CPU::RES5a() { registers.a&=0xDF; registers.m=2; }
void CPU::RES5m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i&=0xDF; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::SET5b() { registers.b|=0x20; registers.m=2; }
void CPU::SET5c() { registers.b|=0x20; registers.m=2; }
void CPU::SET5d() { registers.b|=0x20; registers.m=2; }
void CPU::SET5e() { registers.b|=0x20; registers.m=2; }
void CPU::SET5h() { registers.b|=0x20; registers.m=2; }
void CPU::SET5l() { registers.b|=0x20; registers.m=2; }
void CPU::SET5a() { registers.b|=0x20; registers.m=2; }
void CPU::SET5m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i|=0x20; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::BIT6b() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.b&0x40)?0:0x80; registers.m=2; }
void CPU::BIT6c() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.c&0x40)?0:0x80; registers.m=2; }
void CPU::BIT6d() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.d&0x40)?0:0x80; registers.m=2; }
void CPU::BIT6e() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.e&0x40)?0:0x80; registers.m=2; }
void CPU::BIT6h() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.h&0x40)?0:0x80; registers.m=2; }
void CPU::BIT6l() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.l&0x40)?0:0x80; registers.m=2; }
void CPU::BIT6a() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.a&0x40)?0:0x80; registers.m=2; }
void CPU::BIT6m() { registers.f&=0x1F; registers.f|=0x20; registers.f=(mmu->ReadByte((registers.h<<8)+registers.l)&0x40)?0:0x80; registers.m=3; }

void CPU::RES6b() { registers.b&=0xBF; registers.m=2; }
void CPU::RES6c() { registers.c&=0xBF; registers.m=2; }
void CPU::RES6d() { registers.d&=0xBF; registers.m=2; }
void CPU::RES6e() { registers.e&=0xBF; registers.m=2; }
void CPU::RES6h() { registers.h&=0xBF; registers.m=2; }
void CPU::RES6l() { registers.l&=0xBF; registers.m=2; }
void CPU::RES6a() { registers.a&=0xBF; registers.m=2; }
void CPU::RES6m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i&=0xBF; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::SET6b() { registers.b|=0x40; registers.m=2; }
void CPU::SET6c() { registers.b|=0x40; registers.m=2; }
void CPU::SET6d() { registers.b|=0x40; registers.m=2; }
void CPU::SET6e() { registers.b|=0x40; registers.m=2; }
void CPU::SET6h() { registers.b|=0x40; registers.m=2; }
void CPU::SET6l() { registers.b|=0x40; registers.m=2; }
void CPU::SET6a() { registers.b|=0x40; registers.m=2; }
void CPU::SET6m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i|=0x40; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::BIT7b() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.b&0x80)?0:0x80; registers.m=2; }
void CPU::BIT7c() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.c&0x80)?0:0x80; registers.m=2; }
void CPU::BIT7d() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.d&0x80)?0:0x80; registers.m=2; }
void CPU::BIT7e() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.e&0x80)?0:0x80; registers.m=2; }
void CPU::BIT7h() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.h&0x80)?0:0x80; registers.m=2; }
void CPU::BIT7l() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.l&0x80)?0:0x80; registers.m=2; }
void CPU::BIT7a() { registers.f&=0x1F; registers.f|=0x20; registers.f=(registers.a&0x80)?0:0x80; registers.m=2; }
void CPU::BIT7m() { registers.f&=0x1F; registers.f|=0x20; registers.f=(mmu->ReadByte((registers.h<<8)+registers.l)&0x80)?0:0x80; registers.m=3; }

void CPU::RES7b() { registers.b&=0x7F; registers.m=2; }
void CPU::RES7c() { registers.c&=0x7F; registers.m=2; }
void CPU::RES7d() { registers.d&=0x7F; registers.m=2; }
void CPU::RES7e() { registers.e&=0x7F; registers.m=2; }
void CPU::RES7h() { registers.h&=0x7F; registers.m=2; }
void CPU::RES7l() { registers.l&=0x7F; registers.m=2; }
void CPU::RES7a() { registers.a&=0x7F; registers.m=2; }
void CPU::RES7m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i&=0x7F; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::SET7b() { registers.b|=0x80; registers.m=2; }
void CPU::SET7c() { registers.b|=0x80; registers.m=2; }
void CPU::SET7d() { registers.b|=0x80; registers.m=2; }
void CPU::SET7e() { registers.b|=0x80; registers.m=2; }
void CPU::SET7h() { registers.b|=0x80; registers.m=2; }
void CPU::SET7l() { registers.b|=0x80; registers.m=2; }
void CPU::SET7a() { registers.b|=0x80; registers.m=2; }
void CPU::SET7m() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); i|=0x80; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.m=4; }

void CPU::RLA() { auto ci=registers.f&0x10?1:0; auto co=registers.a&0x80?0x10:0; registers.a=(registers.a<<1)+ci; registers.a&=255; registers.f=(registers.f&0xEF)+co; registers.m=1; }
void CPU::RLCA() { auto ci=registers.a&0x80?1:0; auto co=registers.a&0x80?0x10:0; registers.a=(registers.a<<1)+ci; registers.a&=255; registers.f=(registers.f&0xEF)+co; registers.m=1; }
void CPU::RRA() { auto ci=registers.f&0x10?0x80:0; auto co=registers.a&1?0x10:0; registers.a=(registers.a>>1)+ci; registers.a&=255; registers.f=(registers.f&0xEF)+co; registers.m=1; }
void CPU::RRCA() { auto ci=registers.a&1?0x80:0; auto co=registers.a&1?0x10:0; registers.a=(registers.a>>1)+ci; registers.a&=255; registers.f=(registers.f&0xEF)+co; registers.m=1; }

void CPU::RLr_b() { auto ci=registers.f&0x10?1:0; auto co=registers.b&0x80?0x10:0; registers.b=(registers.b<<1)+ci; registers.b&=255; registers.f=(registers.b)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLr_c() { auto ci=registers.f&0x10?1:0; auto co=registers.c&0x80?0x10:0; registers.c=(registers.c<<1)+ci; registers.c&=255; registers.f=(registers.c)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLr_d() { auto ci=registers.f&0x10?1:0; auto co=registers.d&0x80?0x10:0; registers.d=(registers.d<<1)+ci; registers.d&=255; registers.f=(registers.d)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLr_e() { auto ci=registers.f&0x10?1:0; auto co=registers.e&0x80?0x10:0; registers.e=(registers.e<<1)+ci; registers.e&=255; registers.f=(registers.e)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLr_h() { auto ci=registers.f&0x10?1:0; auto co=registers.h&0x80?0x10:0; registers.h=(registers.h<<1)+ci; registers.h&=255; registers.f=(registers.h)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLr_l() { auto ci=registers.f&0x10?1:0; auto co=registers.l&0x80?0x10:0; registers.l=(registers.l<<1)+ci; registers.l&=255; registers.f=(registers.l)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLr_a() { auto ci=registers.f&0x10?1:0; auto co=registers.a&0x80?0x10:0; registers.a=(registers.a<<1)+ci; registers.a&=255; registers.f=(registers.a)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLHL() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); auto ci=registers.f&0x10?1:0; auto co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; registers.f=(i)?0:0x80; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.f=(registers.f&0xEF)+co; registers.m=4; }

void CPU::RLCr_b() { auto ci=registers.b&0x80?1:0; auto co=registers.b&0x80?0x10:0; registers.b=(registers.b<<1)+ci; registers.b&=255; registers.f=(registers.b)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLCr_c() { auto ci=registers.c&0x80?1:0; auto co=registers.c&0x80?0x10:0; registers.c=(registers.c<<1)+ci; registers.c&=255; registers.f=(registers.c)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLCr_d() { auto ci=registers.d&0x80?1:0; auto co=registers.d&0x80?0x10:0; registers.d=(registers.d<<1)+ci; registers.d&=255; registers.f=(registers.d)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLCr_e() { auto ci=registers.e&0x80?1:0; auto co=registers.e&0x80?0x10:0; registers.e=(registers.e<<1)+ci; registers.e&=255; registers.f=(registers.e)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLCr_h() { auto ci=registers.h&0x80?1:0; auto co=registers.h&0x80?0x10:0; registers.h=(registers.h<<1)+ci; registers.h&=255; registers.f=(registers.h)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLCr_l() { auto ci=registers.l&0x80?1:0; auto co=registers.l&0x80?0x10:0; registers.l=(registers.l<<1)+ci; registers.l&=255; registers.f=(registers.l)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLCr_a() { auto ci=registers.a&0x80?1:0; auto co=registers.a&0x80?0x10:0; registers.a=(registers.a<<1)+ci; registers.a&=255; registers.f=(registers.a)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RLCHL() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); auto ci=i&0x80?1:0; auto co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; registers.f=(i)?0:0x80; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.f=(registers.f&0xEF)+co; registers.m=4; }

void CPU::RRr_b() { auto ci=registers.f&0x10?0x80:0; auto co=registers.b&1?0x10:0; registers.b=(registers.b>>1)+ci; registers.b&=255; registers.f=(registers.b)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRr_c() { auto ci=registers.f&0x10?0x80:0; auto co=registers.c&1?0x10:0; registers.c=(registers.c>>1)+ci; registers.c&=255; registers.f=(registers.c)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRr_d() { auto ci=registers.f&0x10?0x80:0; auto co=registers.d&1?0x10:0; registers.d=(registers.d>>1)+ci; registers.d&=255; registers.f=(registers.d)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRr_e() { auto ci=registers.f&0x10?0x80:0; auto co=registers.e&1?0x10:0; registers.e=(registers.e>>1)+ci; registers.e&=255; registers.f=(registers.e)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRr_h() { auto ci=registers.f&0x10?0x80:0; auto co=registers.h&1?0x10:0; registers.h=(registers.h>>1)+ci; registers.h&=255; registers.f=(registers.h)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRr_l() { auto ci=registers.f&0x10?0x80:0; auto co=registers.l&1?0x10:0; registers.l=(registers.l>>1)+ci; registers.l&=255; registers.f=(registers.l)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRr_a() { auto ci=registers.f&0x10?0x80:0; auto co=registers.a&1?0x10:0; registers.a=(registers.a>>1)+ci; registers.a&=255; registers.f=(registers.a)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRHL() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); auto ci=registers.f&0x10?0x80:0; auto co=i&1?0x10:0; i=(i>>1)+ci; i&=255; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.f=(i)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=4; }

void CPU::RRCr_b() { auto ci=registers.b&1?0x80:0; auto co=registers.b&1?0x10:0; registers.b=(registers.b>>1)+ci; registers.b&=255; registers.f=(registers.b)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRCr_c() { auto ci=registers.c&1?0x80:0; auto co=registers.c&1?0x10:0; registers.c=(registers.c>>1)+ci; registers.c&=255; registers.f=(registers.c)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRCr_d() { auto ci=registers.d&1?0x80:0; auto co=registers.d&1?0x10:0; registers.d=(registers.d>>1)+ci; registers.d&=255; registers.f=(registers.d)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRCr_e() { auto ci=registers.e&1?0x80:0; auto co=registers.e&1?0x10:0; registers.e=(registers.e>>1)+ci; registers.e&=255; registers.f=(registers.e)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRCr_h() { auto ci=registers.h&1?0x80:0; auto co=registers.h&1?0x10:0; registers.h=(registers.h>>1)+ci; registers.h&=255; registers.f=(registers.h)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRCr_l() { auto ci=registers.l&1?0x80:0; auto co=registers.l&1?0x10:0; registers.l=(registers.l>>1)+ci; registers.l&=255; registers.f=(registers.l)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRCr_a() { auto ci=registers.a&1?0x80:0; auto co=registers.a&1?0x10:0; registers.a=(registers.a>>1)+ci; registers.a&=255; registers.f=(registers.a)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::RRCHL() { auto i=mmu->ReadByte((registers.h<<8)+registers.l); auto ci=i&1?0x80:0; auto co=i&1?0x10:0; i=(i>>1)+ci; i&=255; mmu->WriteByte((registers.h<<8)+registers.l,i); registers.f=(i)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=4; }

void CPU::SLAr_b() { auto co=registers.b&0x80?0x10:0; registers.b=(registers.b<<1)&255; registers.f=(registers.b)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLAr_c() { auto co=registers.c&0x80?0x10:0; registers.c=(registers.c<<1)&255; registers.f=(registers.c)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLAr_d() { auto co=registers.d&0x80?0x10:0; registers.d=(registers.d<<1)&255; registers.f=(registers.d)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLAr_e() { auto co=registers.e&0x80?0x10:0; registers.e=(registers.e<<1)&255; registers.f=(registers.e)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLAr_h() { auto co=registers.h&0x80?0x10:0; registers.h=(registers.h<<1)&255; registers.f=(registers.h)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLAr_l() { auto co=registers.l&0x80?0x10:0; registers.l=(registers.l<<1)&255; registers.f=(registers.l)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLAr_a() { auto co=registers.a&0x80?0x10:0; registers.a=(registers.a<<1)&255; registers.f=(registers.a)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }

void CPU::SLLr_b() { auto co=registers.b&0x80?0x10:0; registers.b=(registers.b<<1)&255+1; registers.f=(registers.b)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLLr_c() { auto co=registers.c&0x80?0x10:0; registers.c=(registers.c<<1)&255+1; registers.f=(registers.c)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLLr_d() { auto co=registers.d&0x80?0x10:0; registers.d=(registers.d<<1)&255+1; registers.f=(registers.d)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLLr_e() { auto co=registers.e&0x80?0x10:0; registers.e=(registers.e<<1)&255+1; registers.f=(registers.e)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLLr_h() { auto co=registers.h&0x80?0x10:0; registers.h=(registers.h<<1)&255+1; registers.f=(registers.h)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLLr_l() { auto co=registers.l&0x80?0x10:0; registers.l=(registers.l<<1)&255+1; registers.f=(registers.l)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SLLr_a() { auto co=registers.a&0x80?0x10:0; registers.a=(registers.a<<1)&255+1; registers.f=(registers.a)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }

void CPU::SRAr_b() { auto ci=registers.b&0x80; auto co=registers.b&1?0x10:0; registers.b=((registers.b>>1)+ci)&255; registers.f=(registers.b)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRAr_c() { auto ci=registers.c&0x80; auto co=registers.c&1?0x10:0; registers.c=((registers.c>>1)+ci)&255; registers.f=(registers.c)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRAr_d() { auto ci=registers.d&0x80; auto co=registers.d&1?0x10:0; registers.d=((registers.d>>1)+ci)&255; registers.f=(registers.d)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRAr_e() { auto ci=registers.e&0x80; auto co=registers.e&1?0x10:0; registers.e=((registers.e>>1)+ci)&255; registers.f=(registers.e)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRAr_h() { auto ci=registers.h&0x80; auto co=registers.h&1?0x10:0; registers.h=((registers.h>>1)+ci)&255; registers.f=(registers.h)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRAr_l() { auto ci=registers.l&0x80; auto co=registers.l&1?0x10:0; registers.l=((registers.l>>1)+ci)&255; registers.f=(registers.l)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRAr_a() { auto ci=registers.a&0x80; auto co=registers.a&1?0x10:0; registers.a=((registers.a>>1)+ci)&255; registers.f=(registers.a)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }

void CPU::SRLr_b() { auto co=registers.b&1?0x10:0; registers.b=(registers.b>>1)&255; registers.f=(registers.b)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRLr_c() { auto co=registers.c&1?0x10:0; registers.c=(registers.c>>1)&255; registers.f=(registers.c)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRLr_d() { auto co=registers.d&1?0x10:0; registers.d=(registers.d>>1)&255; registers.f=(registers.d)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRLr_e() { auto co=registers.e&1?0x10:0; registers.e=(registers.e>>1)&255; registers.f=(registers.e)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRLr_h() { auto co=registers.h&1?0x10:0; registers.h=(registers.h>>1)&255; registers.f=(registers.h)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRLr_l() { auto co=registers.l&1?0x10:0; registers.l=(registers.l>>1)&255; registers.f=(registers.l)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }
void CPU::SRLr_a() { auto co=registers.a&1?0x10:0; registers.a=(registers.a>>1)&255; registers.f=(registers.a)?0:0x80; registers.f=(registers.f&0xEF)+co; registers.m=2; }

void CPU::CPL() { registers.a ^= 255; registers.f=registers.a?0:0x80; registers.m=1; }
void CPU::NEG() { registers.a=0-registers.a; registers.f=(registers.a<0)?0x10:0; registers.a&=255; if(!registers.a) registers.f|=0x80; registers.m=2; }

void CPU::CCF() { auto ci=registers.f&0x10?0:0x10; registers.f=(registers.f&0xEF)+ci; registers.m=1; }
void CPU::SCF() { registers.f|=0x10; registers.m=1; }

/*--- Stack ---*/
void CPU::PUSHBC() { registers.sp--; mmu->WriteByte(registers.sp,registers.b); registers.sp--; mmu->WriteByte(registers.sp,registers.c); registers.m=3; }
void CPU::PUSHDE() { registers.sp--; mmu->WriteByte(registers.sp,registers.d); registers.sp--; mmu->WriteByte(registers.sp,registers.e); registers.m=3; }
void CPU::PUSHHL() { registers.sp--; mmu->WriteByte(registers.sp,registers.h); registers.sp--; mmu->WriteByte(registers.sp,registers.l); registers.m=3; }
void CPU::PUSHAF() { registers.sp--; mmu->WriteByte(registers.sp,registers.a); registers.sp--; mmu->WriteByte(registers.sp,registers.f); registers.m=3; }

void CPU::POPBC() { registers.c=mmu->ReadByte(registers.sp); registers.sp++; registers.b=mmu->ReadByte(registers.sp); registers.sp++; registers.m=3; }
void CPU::POPDE() { registers.e=mmu->ReadByte(registers.sp); registers.sp++; registers.d=mmu->ReadByte(registers.sp); registers.sp++; registers.m=3; }
void CPU::POPHL() { registers.l=mmu->ReadByte(registers.sp); registers.sp++; registers.h=mmu->ReadByte(registers.sp); registers.sp++; registers.m=3; }
void CPU::POPAF() { registers.f=mmu->ReadByte(registers.sp); registers.sp++; registers.a=mmu->ReadByte(registers.sp); registers.sp++; registers.m=3; }

/*--- Jump ---*/
void CPU::JPnn() { registers.pc = mmu->ReadWord(registers.pc); registers.m=3; }
void CPU::JPHL() { registers.pc=(registers.h<<8)+registers.l; registers.m=1; }
void CPU::JPNZnn() { registers.m=3; if((registers.f&0x80)==0x00) { registers.pc=mmu->ReadWord(registers.pc); registers.m++; } else registers.pc+=2; }
void CPU::JPZnn()  { registers.m=3; if((registers.f&0x80)==0x80) { registers.pc=mmu->ReadWord(registers.pc); registers.m++; } else registers.pc+=2; }
void CPU::JPNCnn() { registers.m=3; if((registers.f&0x10)==0x00) { registers.pc=mmu->ReadWord(registers.pc); registers.m++; } else registers.pc+=2; }
void CPU::JPCnn()  { registers.m=3; if((registers.f&0x10)==0x10) { registers.pc=mmu->ReadWord(registers.pc); registers.m++; } else registers.pc+=2; }

void CPU::JRn() { auto i=mmu->ReadByte(registers.pc); if(i>127) i=-((~i+1)&255); registers.pc++; registers.m=2; registers.pc+=i; registers.m++; }
void CPU::JRNZn() { auto i=mmu->ReadByte(registers.pc); if(i>127) i=-((~i+1)&255); registers.pc++; registers.m=2; if((registers.f&0x80)==0x00) { registers.pc+=i; registers.m++; } }
void CPU::JRZn()  { auto i=mmu->ReadByte(registers.pc); if(i>127) i=-((~i+1)&255); registers.pc++; registers.m=2; if((registers.f&0x80)==0x80) { registers.pc+=i; registers.m++; } }
void CPU::JRNCn() { auto i=mmu->ReadByte(registers.pc); if(i>127) i=-((~i+1)&255); registers.pc++; registers.m=2; if((registers.f&0x10)==0x00) { registers.pc+=i; registers.m++; } }
void CPU::JRCn()  { auto i=mmu->ReadByte(registers.pc); if(i>127) i=-((~i+1)&255); registers.pc++; registers.m=2; if((registers.f&0x10)==0x10) { registers.pc+=i; registers.m++; } }

void CPU::DJNZn() { auto i=mmu->ReadByte(registers.pc); if(i>127) i=-((~i+1)&255); registers.pc++; registers.m=2; registers.b--; if(registers.b) { registers.pc+=i; registers.m++; } }

void CPU::CALLnn() { registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc+2); registers.pc=mmu->ReadWord(registers.pc); registers.m=5; }
void CPU::CALLNZnn() { registers.m=3; if((registers.f&0x80)==0x00) { registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc+2); registers.pc=mmu->ReadWord(registers.pc); registers.m+=2; } else registers.pc+=2; }
void CPU::CALLZnn() { registers.m=3; if((registers.f&0x80)==0x80) { registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc+2); registers.pc=mmu->ReadWord(registers.pc); registers.m+=2; } else registers.pc+=2; }
void CPU::CALLNCnn() { registers.m=3; if((registers.f&0x10)==0x00) { registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc+2); registers.pc=mmu->ReadWord(registers.pc); registers.m+=2; } else registers.pc+=2; }
void CPU::CALLCnn() { registers.m=3; if((registers.f&0x10)==0x10) { registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc+2); registers.pc=mmu->ReadWord(registers.pc); registers.m+=2; } else registers.pc+=2; }

void CPU::RET() { registers.pc=mmu->ReadWord(registers.sp); registers.sp+=2; registers.m=3; }
void CPU::RETI() { registers.ime=1; RRS(); registers.pc=mmu->ReadWord(registers.sp); registers.sp+=2; registers.m=3; }
void CPU::RETNZ() { registers.m=1; if((registers.f&0x80)==0x00) { registers.pc=mmu->ReadWord(registers.sp); registers.sp+=2; registers.m+=2; } }
void CPU::RETZ() { registers.m=1; if((registers.f&0x80)==0x80) { registers.pc=mmu->ReadWord(registers.sp); registers.sp+=2; registers.m+=2; } }
void CPU::RETNC() { registers.m=1; if((registers.f&0x10)==0x00) { registers.pc=mmu->ReadWord(registers.sp); registers.sp+=2; registers.m+=2; } }
void CPU::RETC() { registers.m=1; if((registers.f&0x10)==0x10) { registers.pc=mmu->ReadWord(registers.sp); registers.sp+=2; registers.m+=2; } }

void CPU::RST00() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x00; registers.m=3; }
void CPU::RST08() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x08; registers.m=3; }
void CPU::RST10() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x10; registers.m=3; }
void CPU::RST18() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x18; registers.m=3; }
void CPU::RST20() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x20; registers.m=3; }
void CPU::RST28() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x28; registers.m=3; }
void CPU::RST30() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x30; registers.m=3; }
void CPU::RST38() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x38; registers.m=3; }
void CPU::RST40() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x40; registers.m=3; }
void CPU::RST48() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x48; registers.m=3; }
void CPU::RST50() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x50; registers.m=3; }
void CPU::RST58() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x58; registers.m=3; }
void CPU::RST60() { RSV(); registers.sp-=2; mmu->WriteWord(registers.sp,registers.pc); registers.pc=0x60; registers.m=3; }

void CPU::NOP() { registers.m=1; }
void CPU::HALT() { halt=true; registers.m=1; }

void CPU::DI() { registers.ime=0; registers.m=1; }
void CPU::EI() { registers.ime=1; registers.m=1; }

void CPU::LDmmSP() {}

// helper functions
void CPU::RSV() {
    temp_registers.a = registers.a; temp_registers.b = registers.b;
    temp_registers.c = registers.c; temp_registers.d = registers.d;
    temp_registers.e = registers.e; temp_registers.f = registers.f;
    temp_registers.h = registers.h; temp_registers.l = registers.l;
}

void CPU::RRS() {
    registers.a = temp_registers.a; registers.b = temp_registers.b;
    registers.c = temp_registers.c; registers.d = temp_registers.d;
    registers.e = temp_registers.e; registers.f = temp_registers.f;
    registers.h = temp_registers.h; registers.l = temp_registers.l;
}

void CPU::MAPcb() {
    auto op_code = mmu->ReadByte(registers.pc); registers.pc++;
    ExecuteCBInstruction(op_code);
}

void CPU::XX() {
    // undefined map entry
    auto op_code = registers.pc-1;
    std::cout << "OpCode: '" << ToHexString(op_code) << "'" << std::endl;
    stop=true;
}