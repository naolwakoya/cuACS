# cuACS
Used C++to design, develop, and test software for Carleton University Animal Care System; resulting in an accurate match of the most optimal sets of clients and pets

# Features

`Clients can view a list of all animals available for adoption, and they can view the detailed profile of a
selected animal. Clients can also edit their own profile, where they can update their personal information
and their matching preferences.
Shelter staff can view a list of all animals available for adoption, and they can view the detailed profile of a
selected animal. They can add a new animal and edit any animal’s profile information. Shelter staff can
also view a list of all existing clients, and they can view the detailed profile of a selected client. They can
also add new clients. Most importantly, staff members can launch the execution of the ACM algorithm and
view the resulting matches. The ACM algorithm uses animal and client profiles to compute the best
matches, and it outputs the match results. These results must consist of both a summary of matches, and
the details of a selected match. The summary information indicates the names of the matched pairs of
animals and clients. The detailed information for a given match specifies the exact rules that were used to
compute that match, as well as the data supporting how and why that specific match was computed.
COMP`

# Technical Specifications
`The Linux Ubuntu platform, as provided in the official course virtual machine (VM), will be used as the test
bed for evaluating the cuACS system. All source code must be written in C++, and it must be designed and
implemented at the level of a 3rd year undergraduate Computer Science student, using advanced OO
techniques such as polymorphism and design patterns.`

# Animal-Client Matching (ACM) Algorithm
`Every development team implementing the cuACS system will define a set of attributes (or qualities) that
they believe are important in matching together compatible animals and human clients and likely to result
in a successful adoption. Some attributes will be physical, such as type of animal, breed, gender, age, and
size. Non-physical attributes will relate to temperament, personality traits, habits, etc. Specific values for
these attributes will be included in every animal profile. A client profile will contain specific values for the
attributes that are relevant to humans in the adoption process, as part of the client’s personal data. Each
client profile must also contain the client’s matching preferences, which are the values for the attributes
that the client is looking for in an adopted animal.
Once a development team has defined a set of attributes, they must design their own cuACS animal-client
matching (ACM) algorithm. The algorithm must use its own unique set of rules for matching together animal
and client profiles, based on the attributes and matching preferences contained in those profiles. Each
development team’s ACM algorithm will be evaluated based on the variety, originality, and appropriateness
of its matching rules and attributes.
In addition to the basic physical attributes (type of animal, breed, gender, age range, etc), the algorithm
must use a minimum of 12 (twelve) separate and unique non-physical attributes. All the attributes defined
in the animal and client profiles must be used by the algorithm’s rules to compute the best matches. This
includes a client’s own attributes, as well as their matching preferences.`
