/* featuremanager.h: The feature manager file.
 *
 * Copyright (C) 2012 Parth Gupta
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#ifndef FEATURE_MANAGER_H
#define FEATURE_MANAGER_H

#include <xapian.h>
#include <xapian/intrusive_ptr.h>
#include <xapian/types.h>
#include <xapian/visibility.h>

#include "letor.h"
#include "letor_features.h"
#include "featurevector.h"
#include "ranklist.h"

#include <map>
#include <string>

using namespace std;

namespace Xapian {

class RankList;
class FeatureVector;

class XAPIAN_VISIBILITY_DEFAULT FeatureManager {

  public:

    class Internal;

    Xapian::Internal::intrusive_ptr<Internal> internal;

    FeatureManager();

    FeatureManager(const FeatureManager & o);

    FeatureManager & operator=(const FeatureManager & o);

    ~FeatureManager();

    std::map<int,double> transform(const Document &doc, double &weight_);

    Xapian::RankList create_rank_list(const Xapian::MSet & mset,std::string & qid);

    map<string, map<string,int> > load_relevance(const std::string & qrel_file);    
    
    Xapian::FeatureVector create_feature_vector(map<int,double> fvals, int &label, std::string & did);
    
    std::string getdid(const Document &doc);
    
    int getlabel(map<string, map<string, int> > qrel, const Document &doc, std::string & qid);

    static const int fNum = 20;

    // accessors
    void set_database(const Database &db);
    // const Database &get_database();
    void set_query(const Query &query);
    // const Query &get_query();

};

}

#endif // FEATURE_MANAGER_H