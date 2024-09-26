#include "temp_field.hpp"

namespace Diff{

auto generate_pos(std::size_t index, int length, int height){
    PosID result;
    result[0]=index%length;
    result[1]=index/height+1;
    return result;
}


std::vector<Section2D> generate_field(std::default_random_engine& eng,int length, int height, double tempmin, double tempmax){
    std::vector<Section2D> field(length*height);
    std::uniform_real_distribution<double> dist(tempmin,tempmax);
    int i=0;
    std::for_each(field.begin(),field.end(),[&](auto& temp){
        Section2D result;
        result.position=generate_pos(i,length,height);
        result.temp=dist(eng);
        field.push_back(result);
        ++i;
    });
}
void update_map(MyMap & map, std::vector<Section2D>const& field){
    map.clear();
    std::for_each(field.begin(), field.end(),[](auto& section){
        map.insert(section.position,&section);
    });
}

void TempField::update(){
std::for_each(_field.begin(),_field.end(),[](auto& section){
    double temp_derivative;
    if(section.position[0]==1||section.position[1]==1){
        PosID fw_x{section.position[0]+1,section.position[1]};
        PosID ffw_x{section.position[0]+2,section.position[1]};

        temp_derivative=laplacian_FDD(*(_map.find(PosID{section.position[0]+1,s})))
    }

});


}

}