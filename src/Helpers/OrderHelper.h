#pragma once

//using Robot.Common.Models;
//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading;
//using System.Threading.Tasks;

//namespace Robot.Common.Helpers
//{
//    public static class OrderHelper
//    {
//        private  static int CoinCount;
//        private  static Dictionary<string, double> coinAvailable;
//        private  static Coin[] coinArray;
//        private  static bool runLive = true;
//        private  static Dictionary<int, Dictionary<int, MarketPair>> wayHome;
//       // private static ReadPathStep readPath;
//        private  static MarketPair[] marketPairArray;
//        private  static object lockClient = new Object();

//        //private Dictionary<string, MarketPair> marketPairDict;
//        //private CoinbaseClient client;
//        //private Dictionary<int, Dictionary<int, ExchaingMap>> exchangeMap;

//        public static void OrderHelperInit(MarketPair[] mp,Coin[] ca, CoinBalances coinBalances)//, ReadPathStep rp)//, Dictionary<string, MarketPair> mpd)
//        {
//            marketPairArray = mp;
//            //readPath = rp;
//            wayHome = new Dictionary<int, Dictionary<int, MarketPair>>();
//            coinArray = ca;
//            for (int i = 0; i < coinArray.Length; i++)
//            {
//                wayHome.Add(coinArray[i].Id, new Dictionary<int, MarketPair>());

//                foreach (MarketPair pair in coinArray[i].QuoteMarkets)
//                {
//                    if (coinArray[i].Id == pair.QuoteCurrency.Id)
//                    {
//                        wayHome[coinArray[i].Id].Add(pair.BaseCurrency.Id, pair);
//                    }
//                    else
//                    {
//                        wayHome[coinArray[i].Id].Add(pair.QuoteCurrency.Id, pair);
//                    }
//                }

//                foreach (MarketPair pair in coinArray[i].BaseMarkets)
//                {
//                    if (coinArray[i].Id == pair.QuoteCurrency.Id)
//                    {
//                        wayHome[coinArray[i].Id].Add(pair.BaseCurrency.Id, pair);
//                    }
//                    else
//                    {
//                        wayHome[coinArray[i].Id].Add(pair.QuoteCurrency.Id, pair);
//                    }
//                }
//            }

//            CoinCount = coinArray.Length;

//            coinAvailable = new Dictionary<string, double>();

//            for (int i = 0; i < CoinCount; i++)
//            {
//                coinAvailable.Add(coinArray[i].Symbol, 0.0);
//            }

//            var accounts = client.Accounts.GetAllAccountsAsync();
//            accounts.Wait();

//            foreach (var account in accounts.Result)
//            {
//                string cName = account.Currency;

//                if (cName.Length > 5)
//                    cName = cName.Substring(0,5);
//                if (coinAvailable.ContainsKey(cName))
//                {
//                    if (account.Available > 0.0m)
//                    {
//                        coinAvailable[cName] = (double)account.Available;
//                    }
//                    else
//                    {
//                        coinAvailable[account.Currency] = 0.0;
//                    }
//                }
//            }

//            for (int i = 0; i < CoinCount; i++)
//            {
//                if (coinAvailable[coinArray[i].Symbol] > 0.0)
//                {
//                    coinBalances.SetCoinBalanceByIndex(CoinCount, 0.0, i, coinAvailable[coinArray[i].Symbol]);
//                }
//            }

//            coinBalances.RequestSwitch(1);

//            coinBalances.RespondToValueRequest();

//            coinBalances.LoadSwitchBalances();

//        }

//        public static void CheckBalances(CoinBalances coinBalances, bool[] coinBalUpdates)
//        {
//            var accounts = client.Accounts.GetAllAccountsAsync();
//            Thread.Sleep(1000);
//            accounts.Wait();

//            foreach (var account in accounts.Result)
//            {
//                string cName = account.Currency;

//                if (cName.Length > 5)
//                    cName = cName.Substring(0,5);
//                if (coinAvailable.ContainsKey(cName))
//                {
//                    if (account.Available > 0.0m)
//                    {
//                        coinAvailable[cName] = (double)account.Available;
//                    }
//                    else
//                    {
//                        coinAvailable[account.Currency] = 0.0;
//                    }
//                }
//            }

//            bool update = false;

//            for (int i = 0; i < CoinCount; i++)
//            {
//                coinBalUpdates[i] = true;
//                if (coinAvailable[coinArray[i].Symbol] != coinBalances.liveCoinBalances[i])
//                {
//                    update = true;
//                    coinBalances.SetCoinBalanceByIndex(CoinCount, 0.0, i, coinAvailable[coinArray[i].Symbol] - coinBalances.liveCoinBalances[i]);
//                }
//            }

//            if (update)
//            {

//                coinBalances.RequestSwitch(1);

//                coinBalances.RespondToValueRequest();

//                coinBalances.LoadSwitchBalances();

//                //Log.Information("Switched Balances:");

//                //for (int i = 0; i < coinArray.Length; ++i)
//                //{
//                //    //decimal value = 0.0m;
//                //    //coinBalances.GetCoinBalanceByIndex(i, out value);

//                //    if (coinBalances.liveCoinBalances[i] > 0.0)
//                //    {
//                //        Log.Information(coinArray[i].Symbol + " " + coinBalances.liveCoinBalances[i]);
//                //    }
//                //}
//            }

//        }

//        public static bool MakeLoadedGoodOrder0(double amount, StringBuilder sb, out int toCoinId)
//        {
//            double value = 0.0;
//            int market = 0;
//            int orderSide = 2;
//            int amountType = 2;
//            int percision = 10;

//            SavePathStep.GetPathStep(0, out value, out market, out orderSide, out amountType, out percision, out toCoinId);

//            amount = Math.Truncate(amount * (Math.Pow(10.0, percision))) / Math.Pow(10.0, percision);

//            if (amount == 0)
//                sb.AppendLine("ammount == 0");


//            try
//            {
//                lock (lockClient)
//                {
//                    //var order = clientPro.OrdersService.PlaceMarketOrderAsync((CoinbasePro.Services.Orders.Types.OrderSide)orderSide, marketPairArray[market].Symbol, (decimal)amount, (CoinbasePro.Services.Orders.Types.MarketOrderAmountType)amountType);
//                    //Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    sb.AppendLine("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    //order.Wait();
//                }

//                if (SavePathStep.GetIndex1() > 900)
//                    throw new Exception("end of the line");
//                else
//                    return true;
//            }
//            catch (Exception e)
//            {
//                // Log.Error("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                sb.AppendLine("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                // Log.Error(e.Message);
//                throw new Exception("bad order");
//            }
//        }
//        public static bool MakeLoadedGoodOrder1(double amount, StringBuilder sb, out int toCoinId)
//        {
//            double value = 0.0;
//            int market = 0;
//            int orderSide = 2;
//            int amountType = 2;
//            int percision = 10;

//            SavePathStep.GetPathStep(1, out value, out market, out orderSide, out amountType, out percision, out toCoinId);

//            amount = Math.Truncate(amount * (Math.Pow(10.0, percision))) / Math.Pow(10.0, percision);

//            if (amount == 0)
//                sb.AppendLine("ammount == 0");

//            try
//            {
//                lock (lockClient)
//                {
//                    //var order = clientPro.OrdersService.PlaceMarketOrderAsync((CoinbasePro.Services.Orders.Types.OrderSide)orderSide, marketPairArray[market].Symbol, (decimal)amount, (CoinbasePro.Services.Orders.Types.MarketOrderAmountType)amountType);
//                    //Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    sb.AppendLine("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    //order.Wait();
//                }

//                if (SavePathStep.GetIndex2() > 900)
//                    throw new Exception("end of the line");
//                else
//                    return true;
//            }
//            catch (Exception e)
//            {
//                // Log.Error("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                sb.AppendLine("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                // Log.Error(e.Message);
//                throw new Exception("bad order");
//            }
//        }
//        public static bool MakeLoadedGoodOrder2(double amount, StringBuilder sb, out int toCoinId)
//        {
//            double value = 0.0;
//            int market = 0;
//            int orderSide = 2;
//            int amountType = 2;
//            int percision = 10;

//            SavePathStep.GetPathStep(2, out value, out market, out orderSide, out amountType, out percision, out toCoinId);

//            amount = Math.Truncate(amount * (Math.Pow(10.0, percision))) / Math.Pow(10.0, percision);

//            if (amount == 0)
//                sb.AppendLine("ammount == 0");

//            try
//            {
//                lock (lockClient)
//                {
//                    //var order = clientPro.OrdersService.PlaceMarketOrderAsync((CoinbasePro.Services.Orders.Types.OrderSide)orderSide, marketPairArray[market].Symbol, (decimal)amount, (CoinbasePro.Services.Orders.Types.MarketOrderAmountType)amountType);
//                    //Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    sb.AppendLine("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    //order.Wait();
//                }

//                if (SavePathStep.GetIndex3() > 900)
//                    throw new Exception("end of the line");
//                else
//                    return true;
//            }
//            catch (Exception e)
//            {
//                // Log.Error("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                sb.AppendLine("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                // Log.Error(e.Message);
//                throw new Exception("bad order");
//            }
//        }
//        public static bool MakeLoadedGoodOrder3(double amount, StringBuilder sb, out int toCoinId)
//        {
//            double value = 0.0;
//            int market = 0;
//            int orderSide = 2;
//            int amountType = 2;
//            int percision = 10;

//            SavePathStep.GetPathStep(3, out value, out market, out orderSide, out amountType, out percision, out toCoinId);

//            amount = Math.Truncate(amount * (Math.Pow(10.0, percision))) / Math.Pow(10.0, percision);

//            if (amount == 0)
//                sb.AppendLine("ammount == 0");

//            try
//            {
//                lock (lockClient)
//                {
//                    //var order = clientPro.OrdersService.PlaceMarketOrderAsync((CoinbasePro.Services.Orders.Types.OrderSide)orderSide, marketPairArray[market].Symbol, (decimal)amount, (CoinbasePro.Services.Orders.Types.MarketOrderAmountType)amountType);
//                    //Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    sb.AppendLine("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    //order.Wait();
//                }

//                if (SavePathStep.GetIndex4() > 900)
//                    throw new Exception("end of the line");
//                else
//                    return true;
//            }
//            catch (Exception e)
//            {
//                // Log.Error("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                sb.AppendLine("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                // Log.Error(e.Message);
//                throw new Exception("bad order");
//            }
//        }
//        public static bool MakeLoadedGoodOrder4(double amount, StringBuilder sb, out int toCoinId)
//        {
//            double value = 0.0;
//            int market = 0;
//            int orderSide = 2;
//            int amountType = 2;
//            int percision = 10;

//            SavePathStep.GetPathStep(4, out value, out market, out orderSide, out amountType, out percision, out toCoinId);

//            amount = Math.Truncate(amount * (Math.Pow(10.0, percision))) / Math.Pow(10.0, percision);

//            if (amount == 0)
//                sb.AppendLine("ammount == 0");

//            try
//            {
//                lock (lockClient)
//                {
//                    //var order = clientPro.OrdersService.PlaceMarketOrderAsync((CoinbasePro.Services.Orders.Types.OrderSide)orderSide, marketPairArray[market].Symbol, (decimal)amount, (CoinbasePro.Services.Orders.Types.MarketOrderAmountType)amountType);
//                    //Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    sb.AppendLine("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                    //order.Wait();
//                }

//                return true;
//            }
//            catch (Exception e)
//            {
//                // Log.Error("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                sb.AppendLine("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//                // Log.Error(e.Message);
//                throw new Exception("bad order");
//            }
//        }

//        //public static int MakeLoadedGoodOrder(double amount, int index, StringBuilder sb, out int toCoinId)
//        //{
//        //    double value = 0.0;
//        //    int market = 0;
//        //    int orderSide = 2;
//        //    int amountType = 2;
//        //    int percision = 10;

//        //    SavePathStep.GetPathStep(index, out value, out market, out orderSide, out amountType, out percision, out toCoinId);

//        //    if (market > 900)
//        //        return 0;

//        //    amount = Math.Truncate(amount * (Math.Pow(10.0, percision))) / Math.Pow(10.0, percision);

//        //    if (amount == 0)
//        //        sb.AppendLine("ammount == 0");

//        //    try
//        //    {
//        //        //var order = clientPro.OrdersService.PlaceMarketOrderAsync((CoinbasePro.Services.Orders.Types.OrderSide)orderSide, marketPairArray[market].Symbol, (decimal)amount, (CoinbasePro.Services.Orders.Types.MarketOrderAmountType)amountType);
//        //        //Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//        //        sb.AppendLine("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//        //        //order.Wait();

//        //        return SavePathStep.GetNextIndex(index);
//        //    }
//        //    catch (Exception e)
//        //    {
//        //        // Log.Error("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//        //        sb.AppendLine("Failed placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " q " + amount);
//        //        // Log.Error(e.Message);
//        //        return -1;
//        //    }
//        //}
//    }
//}
