

bool sort_pair(const std::pair<int,double> &lhs, const std::pair<int,double> &rhs){
	return lhs.second > rhs.second;
}

void SortTest() {


	TRandom3* m_random = new TRandom3(23789);

	std::vector< double > jet_pt;
	std::vector< double > jet_dl1;

	std::vector< std::pair<int,double> > jet_index_DL1;

	for(unsigned int n = 0; n < 5; ++n) {

		const double dl1 = m_random->Uniform(0.0,5.0);
		const double pt = m_random->Uniform(0.0,200.0);

		jet_dl1.push_back( dl1 );
		jet_pt.push_back( pt );

		std::cout << n << " " << dl1 << " " << pt << std::endl;

		std::pair<int,double> tmp;

		tmp.first = n;
		tmp.second = dl1;

		jet_index_DL1.push_back(tmp);

	}


	std::sort(jet_index_DL1.begin(), jet_index_DL1.end(),sort_pair);

	std::cout << "------ Sorted -------" << std::endl;

	for(unsigned int i = 0; i < jet_index_DL1.size(); ++i ) {

		const unsigned int index = jet_index_DL1.at(i).first;

		std::cout << jet_index_DL1.at(i).first << " " << jet_index_DL1.at(i).second << " " <<  jet_pt.at(index) << std::endl;



	}


}