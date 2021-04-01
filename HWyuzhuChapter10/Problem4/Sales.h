#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

namespace SALES
{
	class Sales
	{
		private:
			static const int QUARTERS = 4;
			double sales[QUARTERS];
			double size;
			double average;
			double max;
			double min;

		private:
			double CalAve (void);
			double CalMax (void);
			double CalMin (void);

		public:
			Sales () {setSales();}
			Sales (double arr[], int n);
			void setSales(void);
			void showSales(void);
	};
}


#endif // SALES_H_INCLUDED
