#include "include/conf.hpp"

void Configuration::InitConfiguration() {
    Configuration::participant_config[P_PORT] = 44500; // P_PORT, 0
       
    Configuration::registrar_config[R_PORT] = 44400; // R_PORT, 0
}
