class UndergroundSystem {
public:
    map<pair<string, string>, pair<int, double>> avgtime;
    map<int, pair<string, int>> onJourney;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        onJourney[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto j = onJourney[id];
        avgtime[{j.first, stationName}].first += t - j.second;
        avgtime[{j.first, stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto x = avgtime[{startStation, endStation}];
        return x.first/x.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */