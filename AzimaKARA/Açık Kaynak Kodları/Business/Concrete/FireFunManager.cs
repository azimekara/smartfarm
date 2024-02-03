using Business.Abstract;
using DataAccess.Abstract;
using Entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Concrete
{
    public class FireFunManager : IFireFunService
    {
        private readonly IFireFunDal _fireFunDal;

        public FireFunManager(IFireFunDal fireFunDal)
        {
            _fireFunDal = fireFunDal;
        }

        public void Add(FireFun fireFun)
        {
           _fireFunDal.Insert(fireFun);
        }

        public async Task<FireFun> EndDataGet()
        {
            var data = await _fireFunDal.GetList();
           return data.OrderByDescending(x => x.Id).FirstOrDefault();
        }
    }
}
