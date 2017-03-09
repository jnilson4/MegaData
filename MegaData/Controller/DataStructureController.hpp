//
//  DataStructureController.hpp
//  MegaData
//
//  Created by Nilson, Jake on 2/8/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "../Model/Node.hpp"
#include "../Model/Array.hpp"
#include "../Model/Timer.hpp"
#include "../Model/IntNodeArray.hpp"
#include "../Model/List.hpp"
#include "../Model/DoubleList.hpp"
#include "../Model/Stack.hpp"
#include "../Model/Queue.hpp"
#include "../Model/CircularList.hpp"
#include <string>

using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
    void testDestructor();
    void testAdvancedFeatures();
    void testListIntro();
    void testDoubleLists();
    void testListTiming();
public:
    DataStructureController();
    void start();
};

#endif /* DataStructureController_hpp */
