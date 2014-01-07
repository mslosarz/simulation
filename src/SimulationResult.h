/*
 * SimulationResult.h
 *
 *  Created on: 9 gru 2013
 */

#ifndef SIMULATIONRESULT_H_
#define SIMULATIONRESULT_H_

class SimulationResult {
public:
	SimulationResult() :
			shopIncome(0), leftPriceOfProducts(0) {
	}
	virtual ~SimulationResult() {
	}

	float getLeftPriceOfProducts() const {
		return leftPriceOfProducts;
	}

	void setLeftPriceOfProducts(float productPrice) {
		this->leftPriceOfProducts = productPrice;
	}

	float getShopIncome() const {
		return shopIncome;
	}

	void setShopIncome(float shopIncome) {
		this->shopIncome = shopIncome;
	}

private:
	float shopIncome;
	float leftPriceOfProducts;
};

#endif /* SIMULATIONRESULT_H_ */
