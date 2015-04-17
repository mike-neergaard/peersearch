#Peer Search
This program is provided under the GPLv3 license. 

Implements a fast search for to select N entries from a dataset of individuals  
such that the entries are "close" to a given N-tuple.  (lat, long, age in the test rig).

You can ~~read in a datafile, or~~ autogenerate a random dataset. The interesting part is the c_bsp class found in space_partition_tree.cpp. The rest is a reasonably interesting model, but mostly serves as a test rig.

This program was generated in response to a programming challenge, and turned out to be interesting.

Instructions
------------
If you type "make", then run "./peersearch" and it works out, then 
don't panic.  Otherwise, feel free to panic. If that's all you wanted 
to know, thanks for reading, and have fun.

Contact Information
-------------------
This program is provided under the GPLv3 license. You can reach the author 
Mike Neergaard at
mike@mikeneergaard.com

Data Model
==========
The data model generates people.  It has two parts -- age distribution and population distribution.
The age and location are generated as independent variables. 

Age Model
---------
The population pyramid in this model draws from the [UN Department of Economic 
and Social Affairs data](http://esa.un.org/unpd/wpp/Excel-Data/population.htm)

Since we want a continuous probability distribution, the pyramid is fit by represented by a Weibull distribution with shape 1.32 and scale 32.9.  


Population Model
----------------
The data is created by sampling from distributions centered on 34 metropolitan areas.  The probability of sampling from a given city is proportional to its population, as listed on [Wikipedia](http://en.wikipedia.org/wiki/List_of_metropolitan_areas_by_population). The geolocation data was drawn from [dateandtime.info](http://dateandtime.info/).  

To accomodate the fact that most cities lie on coasts, the lat and long are drawn from separate distributions.  If there is no coast along that axis, the distribution is normal, else the distribution is one-sided. In the code,, the chosen one-sided distribution is a truncated normal distribution.  

Two cities, Istanbul and Hong Kong, have coasts on at least two sides.  For that case, we draw from a uniform distribution 0.2 degrees wide which is with a factor of 2 for both cities..

The variance of the population gradient was estimated by staring at 
[this](images/Population_gradient.png) graph of population gradients,
and by  [overlaying](images/Population_With_Bell_Curve.png) a bell curve.

Ignoring the apparent population dip in the middle of the city, I chose
0 for the mean and 13 km for 2 sigma.  Translating 6.5 km to degrees (at the equator), let 0.6 degrees be the standard deviation of the bell curve. As mentioned below, the approximation of the earth's surface as a manifold with rectilinear lat long coordinate axes will be close enough for us.

The selected cities are listed below.

City|   Country|Pop|    Lat|    Long|   Direction to Coast (1=N;2=E;4=S;8=W)
----|:--------:|:-:|:-----:|:------:|:--------------------------------------
Tokyo|  Japan|36923000|35.6895000|139.6917100|2
Seoul|  South Korea|25258000|37.5660000|126.9784000|8
Shanghai|China|24750000|31.2222200|121.4580600|2
New York|United States|23484225|40.7142700|-74.0059700|2
Delhi|  India|21753486|28.6538100|77.2289700|0
Mexico City|Mexico|21178959|19.428470|-99.1276600|0
Beijing|China|21148000|39.9075000|116.3972300|0
Mumbai|India|20998395|19.0728300|72.8826100|8
São Paulo|Brazil|20935204|-23.5475000|-46.6361100|4
Jakarta|Indonesia|20000000|-6.2146200|106.8451300|1
Osaka/Kobe/Kyoto|Japan|19342000|34.6937400|135.5021800|8
Cairo|Egypt|16292269|30.0626300|31.2496700|0
Calcutta|India|14617882|22.5626300|88.3630400|0
Bangkok|Thailand|14565547|13.7539800|100.5014400|4
İstanbul|Turkey|14307018|41.0138400|28.9496600|5
London|United Kingdom|13879757|51.5085300|-0.1257400|2
Los Angeles|United States|13131431|34.0522300|-118.2436800|8
Buenos Aires|Argentina | 13074000|-34.6131500|-58.3772300|2
Dhaka|  Bangladesh|12797394|23.7104000|90.4074400|0
Paris|France|11978363|48.8534100|2.3488000|0
Rio de Janeiro|Brazil|11973505|-22.9027800|-43.2075000|6
Manila|Philippines|11855975|14.6042000|120.9822000|8
Rhine-Ruhr|Germany|11470000|51.4565700|7.0122800|0
Lima|Peru|9735587|-12.0431800|-77.0282400|8
Chicago|United States|9537289|41.8500300|-87.6500500|2
Bogotá|Columbia|9512407|4.6097100|-74.0817500|0
Nagoya|Japan|9107000|35.1814700|136.9064100|4
Chennai|India|8917749|13.0878400|80.2784700|2
Bangalore|India|8728906|12.9719400|77.5936900|0
Tehran|Iran|8293140|35.6943900|51.4215100|0
Milan|Italy|8123020|45.4642700|9.1895100|0
Hyderabad|India|7749334|17.3840500|78.4563600|0
Pune|India|7541946|18.5195700|73.8553500|0
Hong Kong|Hong Kong|7234800|22.2855200|114.1576900|14

Names
-----
The names are a random combination of real given names and surnames, drawn from 
a variety of sources, including government statistics, baby books and lists of 
famous people. Aside from the fact that the names roughly correspond to the correct 
parts of the world, there is nothing special about them.  

Considerations
--------------
It would easy and more precise to interpolate the population age histogram. Since the chosen Weibull distribution has a peak, and is not a pyramid, this might seem sensible.  The Weibull distribution was chosen anyway, because
* The histogram itself has a peak
* The Weibull PDF matches the histogram quite well through the middle
* It is an elegant closed-form model, which
* Eliminates some of the noise inherent in measuring at a specific time
* It has parameters that can be tweaked
* Weibull distribution are cool

With respect to the population density gradient, applying a Gaussian on coordinates is _not_ the same as a 2D Gaussian.  A Gaussian applied coordinate-wise is high on the axes and low on the 45 degree lines.  The ability to enforce a population border at the coast, however, takes precedence. Further, metropolitan population densities are hardly smooth, and are highly asymmetric for all kinds of reasons, so the asymmetry of the population density function is likely the least of the problems.

In the set of names, Farsi is not treated separately from Arabic, nor is Portuguese separated
from Spanish Latin American names.  No effort has been made to list first and last names 
in culturally sensitive orders, or to ensure gender matching between given names and 
surnames.  Nonetheless, the names give a good sense of how the retrieval works.

Algorithm
=========
The algorithm preprocesses the data, generating a Binary Space Partition
tree such that the population _P_ of each leaf satisfies _P_ < 2 _T_ for some target population _T_.
The algorithm divides any space into regions with roughly the same population. 

Coordinates and Distance
------------------------
In this case, it is fed latitude, longitude, and age.
The initial region has boundaries defined by 180 W, 180 E, 
90 N, and 90 S. The 180 longitude line is convenient numerically, and 
runs mostly through the unpopulated Pacific Ocean.

The intuition is that each region is a rectangular cuboid.  Locally, on 
flat land not at the poles, the cuboid approximation is good.
Happily for our model, far from the poles is where the population 
resides. 

Since we must make choices between distance spread and age spread, we will
choose 1 year ≈ 1 arcminute (1 year = 2<sup>-6</sup> degrees) by default.

Region Tree
===========
The algorithm preprocesses the data using a build a tree as follows: as data is 
read in, it is assigned to regions.  If a region becomes overpopulated 
according to a threshhold, it is is subdivided across its longest axis.

Since we know in advance what the longest axis is, new data can be kept 
in a sorted container as it is read in, and splitting the data is a 
simple matter of reading the first half into the left leaf, and the
second half into the right leaf.

Once all the data is read in, the population requirements are lowered, and
further splitting takes place.

The idea is that a search N-tuple will of necessity fall 
into a a defined cuboid, and that the population within the cuboid will 
be "close" to the given tuple.  

It is a matter of simple arithmetic to find the closest matches within 
the cuboid using the taxi-cab metric.

Almost all of the parameters specified are configurable.

Open Cover
----------

The binary space partition creates a closed cover.  What we would
prefer is an open cover, where every search terms falls inside a
region.  We can attempt to approximate an open cover as follows:
Nothing in the data structure precludes including extra data 
that spills out over the boundaries.  We'll call the extra data 
_covering data_ by direct analogy with a topological covering space.

Of course, created an open cover  implies that some data points 
are duplicated in the tree with no particular means of correction,
at least not without a map from DB entries to tree data.  Happily,
DB syncronicity is not part of the challenge.

The covering data is kept in 2N separate sets, one for each face. Ergo, if
a point is close to a face, neighbors across the face can be taken into account.

We are missing some neighbors.  An open cover of a cuboid 
intersects 3^n cuboids, while we are using only the facing cuboids. However,
the number of neighbors covered in our scheme goes as Θ(n^(N-1)), where n^N is the
approximate number of points in a cuboid.  The number of neighbors missed, on the
other hand, only goes as O(n^(N-2)). 

Once all data has been read in, the covering data is trimmed, and it
is ready to support searching.

Be careful though -- it takes a long time to pre-process if you add an open cover.

