#include "MovieList.hh"


bool Movie::is_bigger(Movie B){
    if(get_rating() >= B.get_rating()){
        return true;
    }
    else 
        return false;
}


MovieList::MovieList(const std::string & name){
    std::fstream fin;
    uint rows = 0, badrows = 0;
    std::string line, tmp, num;
    int len = 0, val = 0, inval = 0;
    float rating = 0.0;
    std::string title;

    fin.open(name, std::ios::in);
    if( fin.good() != true ){
        throw std::logic_error("Cannot open file!");
    } 

    while (getline(fin, line)){
        if (isdigit(line.back()))
        {
            rows++;
        }
        else{
            badrows++;
        }  
    }
    
    list = new Movie[rows];
    fin.clear();
    fin.seekg(0);

    while (getline(fin, line)){
        if (isdigit(line.back())){
            len = line.length() - 1;
            tmp = line.substr(len - 3, len);

            if(isdigit(tmp[0])){   //ocena = 10.0
                rating  = stof(tmp);
                line.erase(len - 4, len);
            }
            else{   //ocena <10.0
                tmp = tmp.substr(1, 3);
                rating  = stof(tmp);
                line.erase(len - 3, len);
            }
            val++;
            num = std::to_string(val);
            line.erase(0, num.length()+1);
            list[val-1] = Movie(rating, line);
            //std::cout<<tmp<<std::endl;
        }
        else{
            inval++;
        }
        
    }
    std::cout<<"Wczytano: "<<val<<" prawidłowych wierszy"<<std::endl;
    std::cout<<"Nie wczytano: "<<inval<<" nieprawidłowych wierszy"<<std::endl;
}

MovieList::MovieList(const std::string & name, int limit){
    std::fstream fin;
    uint rows = 0, badrows = 0;
    std::string line, tmp, num;
    int len = 0, val = 0, inval = 0;
    float rating = 0.0;
    std::string title;


    fin.open(name, std::ios::in);
    if( fin.good() != true ){
        throw std::logic_error("Cannot open file!");
    } 

    while (getline(fin, line)){
        if (isdigit(line.back()))
        {
            rows++;
        }
        else{
            badrows++;
        }  
    }
    
    list = new Movie[rows];
    fin.clear();
    fin.seekg(0);

    while (getline(fin, line)&&val<limit){
        if (isdigit(line.back())){
            len = line.length() - 1;
            tmp = line.substr(len - 3, len);

            if(isdigit(tmp[0])){   //ocena = 10.0
                rating  = stof(tmp);
                line.erase(len - 4, len);
            }
            else{   //ocena <10.0
                tmp = tmp.substr(1, 3);
                rating  = stof(tmp);
                line.erase(len - 3, len);
            }
            val++;
            num = std::to_string(val+inval);
            line.erase(0, num.length()+1);
            list[val-1] = Movie(rating, line);
        }
        else{
            inval++;
        }
        
    }
    std::cout<<"Wczytano: "<<val<<" prawidłowych wierszy"<<std::endl;
    std::cout<<"Nie wczytano: "<<inval<<" nieprawidłowych wierszy"<<std::endl;
}