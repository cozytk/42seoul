import { ExecutionContext, Injectable } from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';

@Injectable()
export class FtAuthGuard extends AuthGuard('42') {
  handleRequest(err, user, info, context: ExecutionContext) {
    console.log(`😎 ft guard`);
    const { token, username, email } = user;
    if (err || !user) {
      const res = context.switchToHttp().getResponse();
      return res.redirect('/outh');
    }
    return { token, username, email };
  }
}
